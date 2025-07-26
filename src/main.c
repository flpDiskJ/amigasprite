#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_MAX 500

bool run = true;

bool strComp(char *input, char *comp) // compares strings
{
    bool same = true;
    for (int x = 0; x < strlen(comp); x++)
    {
        if (input[x] != comp[x])
        {
            same = false;
        }
    }
    return same;
}

void intro() // intro display
{
    printf(" $$$$$$\\                $$\\                            $$$$$$\\                      $$\\   $$\\ \n");
    printf("$$  __$$\\               \\__|                          $$  __$$\\                     \\__|  $$ |    \n");
    printf("$$ /  $$ |$$$$$$\\$$$$\\  $$\\  $$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\   $$$$$$\\  $$\\ $$$$$$\\    $$$$$$\\ \n");
    printf("$$$$$$$$ |$$  _$$  _$$\\ $$ |$$  __$$\\  \\____$$\\       \\$$$$$$\\  $$  __$$\\ $$  __$$\\ $$ |\\_$$  _|  $$  __$$\\\n");
    printf("$$  __$$ |$$ / $$ / $$ |$$ |$$ /  $$ | $$$$$$$ |       \\____$$\\ $$ /  $$ |$$ |  \\__|$$ |  $$ |    $$$$$$$$ | \n");
    printf("$$ |  $$ |$$ | $$ | $$ |$$ |$$ |  $$ |$$  __$$ |      $$\\   $$ |$$ |  $$ |$$ |      $$ |  $$ |$$\\ $$   ____| \n");
    printf("$$ |  $$ |$$ | $$ | $$ |$$ |\\$$$$$$$ |\\$$$$$$$ |      \\$$$$$$  |$$$$$$$  |$$ |      $$ |  \\$$$$  |\\$$$$$$$\\ \n");
    printf("\\__|  \\__|\\__| \\__| \\__|\\__| \\____$$ | \\_______|       \\______/ $$  ____/ \\__|      \\__|   \\____/  \\_______| \n");
    printf("                            $$|   $$ |                          $$ | \n");
    printf("                            \\$$$$$$  |                          $$ |\n");
    printf("                             \\______/                           |__|\n");
    printf("By Jake Aigner, July 2025\n\n");
}


void help() // lists commands
{
    printf("        List of Commands:\n");
    printf("            endshell :    quit.\n");
    printf("            help     :    command list.\n");
}


void shell() // handles user input
{
    char input[INPUT_MAX];
    printf("? -> ");
    fgets(input, INPUT_MAX, stdin);
    char command[INPUT_MAX];
    char arg[INPUT_MAX];
    command[0] = '\0';
    arg[0] = '\0';
    char *token = strtok(input, " \n\t\r");
    strcpy(command, token);
    token = strtok(NULL, " \n\t\r");
    if (token != NULL)
    {
        strcpy(arg, token);
    }

    if (strComp(command, "endshell\0"))
    {
        run = false;
    }
    else if (strComp(command, "help\0"))
    {
        help();
    }
}

int main()
{
    intro();
    while (run)
    {
        shell();
    }
    return 0;
}
