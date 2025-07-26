#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_MAX 500
#define MAX_VHEIGHT 256

bool run = true;
int v_pos = 0;
char sprite[MAX_VHEIGHT][16];   // amiga sprites have a set width of 16 but infinite height

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
    printf("    List of Commands:\n");
    printf("        endshell :    quit.\n");
    printf("        reset    :    reset sprite\n");
    printf("        gen      :    generate sprite hex data from entered values\n");
    printf("\n  color data can be entered in one line at a time (width of 16)\n");
    printf("  0 = transparent\n  1-3 = sprite colors (check hardware manual for more info)");
    printf("\n\n  example:\n");
    printf("    > reset\n");
    printf("    > 0000012233221000\n");
    printf("    > 0001223333332210\n");
    printf("    > 0000012233221000\n");
    printf("    > gen\n");
}

void reset()
{
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < v_pos; x++)
        {
            sprite[x][y] = '0';
        }
    }
    v_pos = 0;
}

void enter_data(char *line)
{
    if (strlen(line) != 16)
    {
        printf("E: length must be 16!\n");
        return;
    }
    for (int x = 0; x < 16; x++)
    {
        sprite[v_pos][x] = line[x];
    }
    if (v_pos < MAX_VHEIGHT)
    {
        v_pos++;
    } else {
        printf("E: max height!\n");
    }
}

void bin2hex(char *b)
{
    if (strComp(b, "0000\0"))
    {
        printf("0");
    } else if (strComp(b, "0001\0"))
    {
        printf("1");
    } else if (strComp(b, "0010\0"))
    {
        printf("2");
    } else if (strComp(b, "0011\0"))
    {
        printf("3");
    } else if (strComp(b, "0100\0"))
    {
        printf("4");
    } else if (strComp(b, "0101\0"))
    {
        printf("5");
    } else if (strComp(b, "0110\0"))
    {
        printf("6");
    } else if (strComp(b, "0111\0"))
    {
        printf("7");
    } else if (strComp(b, "1000\0"))
    {
        printf("8");
    } else if (strComp(b, "1001\0"))
    {
        printf("9");
    } else if (strComp(b, "1010\0"))
    {
        printf("A");
    } else if (strComp(b, "1011\0"))
    {
        printf("B");
    } else if (strComp(b, "1100\0"))
    {
        printf("C");
    } else if (strComp(b, "1101\0"))
    {
        printf("D");
    } else if (strComp(b, "1110\0"))
    {
        printf("E");
    } else if (strComp(b, "1111\0"))
    {
        printf("F");
    }
}

void generate()
{
    char h_bits[16], l_bits[16];
    long int val = 0;
    printf("\nsprite:");
    printf("\n    DC.W $XXYY,$ZZ00    ;VSTART (XX),HSTART (YY),VSTOP (ZZ) (VSTOP = VSTART + %d)", v_pos);
    for (int v = 0; v < v_pos; v++)
    {
        for (int i = 0; i < 16; i++)
        {
            switch (sprite[v][i]) {
                case '0':
                    h_bits[i] = '0';
                    l_bits[i] = '0';
                    break;
                case '1':
                    h_bits[i] = '0';
                    l_bits[i] = '1';
                    break;
                case '2':
                    h_bits[i] = '1';
                    l_bits[i] = '0';
                    break;
                case '3':
                    h_bits[i] = '1';
                    l_bits[i] = '1';
                    break;
                default:
                    h_bits[i] = '0';
                    l_bits[i] = '0';
                    break;
            }
        }
        printf("\n    DC.W $");
        bin2hex(&l_bits[0]);
        bin2hex(&l_bits[4]);
        bin2hex(&l_bits[8]);
        bin2hex(&l_bits[12]);
        printf(",$");
        bin2hex(&h_bits[0]);
        bin2hex(&h_bits[4]);
        bin2hex(&h_bits[8]);
        bin2hex(&h_bits[12]);
    }
    printf("\n    DC.W $0000,$0000    ;end of sprite data\n\n");
}

void shell() // handles user input
{
    char input[INPUT_MAX];
    printf("> ");
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
    else if (strComp(command, "reset\0"))
    {
        reset();
    }
    else if (strComp(command, "gen\0"))
    {
        generate();
    }
    else if (strComp(command, "clear\0"))
    {
        system("clear");
        intro();
    } else {
        enter_data(command);
    }
}

int main()
{
    system("clear");
    intro();
    while (run)
    {
        shell();
    }
    return 0;
}
