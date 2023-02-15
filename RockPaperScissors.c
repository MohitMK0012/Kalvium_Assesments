#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

struct player
{
    char name[MAX_NAME_LEN];
    int score;
};

int read_score(char *name)
{
    FILE *fp;
    struct player p;

    fp = fopen("score.dat", "rb");
    if (fp == NULL)
    {
        return 0;
    }

    int high_score = 0;
    while (fread(&p, sizeof(struct player), 1, fp) == 1)
    {
        if (strcmp(p.name, name) == 0)
        {
            high_score = p.score;
            break;
        }
    }

    fclose(fp);
    return high_score;
}

void write_score(char *name, int score)
{
    FILE *fp;
    struct player p;
    int found = 0;

    fp = fopen("score.dat", "r+b");
    if (fp == NULL)
    {
        fp = fopen("score.dat", "wb");
        if (fp == NULL)
        {
            printf("Error: Cannot open file!\n");
            return;
        }
    }

    while (fread(&p, sizeof(struct player), 1, fp) == 1)
    {
        if (strcmp(p.name, name) == 0)
        {
            if (score > p.score)
            {
                p.score = score;
                fseek(fp, -sizeof(struct player), SEEK_CUR);
                fwrite(&p, sizeof(struct player), 1, fp);
                printf("Congratulations! You beat the highest score.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        strcpy(p.name, name);
        p.score = score;
        fwrite(&p, sizeof(struct player), 1, fp);
    }

    fclose(fp);
}

int main()
{
    char name[MAX_NAME_LEN];
    int high_score;

    printf("Enter your name: ");
    scanf("%s", name);

    high_score = read_score(name);
    printf("Welcome, %s! Your highest score is %d.\n", name, high_score);

    while (1)
    {
        printf("\nRock Paper Scissors - Enter your choice (1=Rock, 2=Paper, 3=Scissors, 4=Quit): ");
        int choice;
        scanf("%d", &choice);

        if (choice == 4)
        {
            break;
        }

        if (choice < 1 || choice > 3)
        {
            printf("Invalid choice. Please choose again.\n");
            continue;
        }

        int result = rand() % 3 + 1;
        if (result == choice)
        {
            printf("Tie!\n");
        }
        else if ((result == 1 && choice == 3) || (result == 2 && choice == 1) || (result == 3 && choice == 2))
        {
            printf("You lose!\n");
        }
        else
        {
            printf("You win!\n");
            high_score++;
        }

        if (high_score < 0)
        {
            high_score = 0;
        }

        write_score(name, high_score);
    }
    return 0;
}

