#include <stdio.h>
#include <string.h>

#define MAX_TOWER 100
#define MAX_BLOCK 1000

void init(int towers, int stacked_num[]);
void push(char stacked_blocks[][MAX_BLOCK], int stacked_num[]);
void pop(char stacked_blocks[][MAX_BLOCK], int stacked_num[]);
void move(char stacked_blocks[][MAX_BLOCK], int stacked_num[]);

int main(void)
{
    int towers;
    scanf("%d", &towers);

    char stacked_blocks[MAX_TOWER][MAX_BLOCK];
    int stacked_num[MAX_TOWER];
    init(towers, stacked_num);

    char op[5];
    while (1) {
        scanf(" %s", op);
        if (strcmp(op, "quit") == 0) {
            break;
        } else if (strcmp(op, "push") == 0) {
            push(stacked_blocks, stacked_num);
        } else if (strcmp(op, "pop") == 0) {
            pop(stacked_blocks, stacked_num);
        } else if (strcmp(op, "move") == 0) {
            move(stacked_blocks, stacked_num);
        } else {
            printf("ERROR\n");
            break;
        }
    }

    return 0;
}

void init(int towers, int stacked_num[])
{
    int i;
    for (i = 0; i < towers; i++) {
        stacked_num[i] = 0;
    }
}

void push(char stacked_blocks[][MAX_BLOCK], int stacked_num[])
{
    int which_tower;
    char color;
    scanf(" %d %c",&which_tower, &color);
    int stacked_num_the = stacked_num[which_tower - 1];
    stacked_blocks[which_tower - 1][stacked_num_the] = color;
    (stacked_num[which_tower - 1])++;
}

void pop(char stacked_blocks[][MAX_BLOCK], int stacked_num[])
{
    int which_tower;
    scanf(" %d", &which_tower);
    int stacked_num_the = stacked_num[which_tower - 1];
    printf("%c\n", stacked_blocks[which_tower  - 1][stacked_num_the - 1]);
    (stacked_num[which_tower - 1])--;
}

void move(char stacked_blocks[][MAX_BLOCK], int stacked_num[])
{
    int from, to;
    scanf(" %d %d", &from, &to);
    int stacked_num_from = stacked_num[from - 1];
    int stacked_num_to = stacked_num[to - 1];
    stacked_blocks[to - 1][stacked_num_to]
        = stacked_blocks[from - 1][stacked_num_from - 1];
    (stacked_num[from - 1])--;
    (stacked_num[to - 1])++;
}