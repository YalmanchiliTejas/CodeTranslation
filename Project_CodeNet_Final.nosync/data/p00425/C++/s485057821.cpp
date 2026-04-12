#include <bits/stdc++.h>

struct Dice {
    std::vector<int> dice;  // {top, front, right, bottom, back, left};
    std::vector<int> NORTH, EAST, WEST, SOUTH, LEFT, RIGHT;
    Dice(): 
        dice{1, 2, 3, 6, 5, 4},
        NORTH{1, 3, 2, 4, 0, 5},
        EAST{5, 1, 0, 2, 4, 3},
        WEST{2, 1, 3, 5, 4, 0},
        SOUTH{4, 0, 2, 1, 3, 5},
        LEFT{0, 5, 1, 3, 2, 4},
        RIGHT{0, 2, 4, 3, 5, 1}
    {}
    int kurukuru(char op) {
        std::vector<int> p;
        if (op == 'N') {
            p = NORTH;
        } else if (op == 'E') {
            p = EAST;
        } else if (op == 'W') {
            p = WEST;
        } else if (op == 'S') {
            p = SOUTH;
        } else if (op == 'L') {
            p = LEFT;
        } else if (op == 'R') {
            p = RIGHT;
        }

        std::vector<int> tmp(6);
        for (int i=0; i<6; ++i)
            tmp[i] = dice[p[i]];

        dice = std::move(tmp);

        return dice[0];
    }
};

int testcase_ends() {
    int n;
    scanf("%d", &n);

    if (n == 0)
        return 1;

    Dice d;
    int res=1;
    for (int i=0; i<n; ++i) {
        char buf[16];
        scanf("%s", buf);
        res += d.kurukuru(buf[0]);
    }

    printf("%d\n", res);
    return 0;
}

int main() {
    while (true)
        if (testcase_ends()) break;

    return 0;
}