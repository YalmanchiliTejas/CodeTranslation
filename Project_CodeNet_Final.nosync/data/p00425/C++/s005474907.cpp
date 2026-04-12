#include <stdio.h>

enum Surface {TOP, BELOW, RIGHT, LEFT, FRONT, BACK};

#define ROTATE(dice, v)\
{\
    int j;\
    int save = dice[v[0]];\
    for (j=0; j<3; j++) {\
        dice[v[j]] = dice[v[j+1]];\
    }\
    dice[v[3]] = save;\
}

int main() {
    while (1) {
        int i;
        int n;
        int dice[6];
        int ans;
    
        scanf("%d", &n);
        if (n == 0) return 0;

        dice[TOP] = 1;
        dice[BELOW] = 6;
        dice[RIGHT] = 3;
        dice[LEFT] = 4;
        dice[FRONT] = 2;
        dice[BACK] = 5;
    
        ans = 1;
        for (i=0; i<n; i++) {
            char dir_s[10];
    
            scanf("%s", dir_s);
            if (dir_s[0] == 'N') {
               int v[4] = {TOP, FRONT, BELOW, BACK};
               ROTATE(dice, v);
            } else if (dir_s[0] == 'E') {
               int v[4] = {TOP, LEFT, BELOW, RIGHT};
               ROTATE(dice, v);
            } else if (dir_s[0] == 'S') {
               int v[4] = {TOP, BACK, BELOW, FRONT};
               ROTATE(dice, v);
            } else if (dir_s[0] == 'W') {
               int v[4] = {TOP, RIGHT, BELOW, LEFT};
               ROTATE(dice, v);
            } else if (dir_s[0] == 'R') {
               int v[4] = {FRONT, RIGHT, BACK, LEFT};
               ROTATE(dice, v);
            } else if (dir_s[0] == 'L') {
               int v[4] = {FRONT, LEFT, BACK, RIGHT};
               ROTATE(dice, v);
            }
    
            ans += dice[TOP];
        }
    
        printf("%d\n", ans);
    }
}