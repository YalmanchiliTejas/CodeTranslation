#include<cstdio>

const int MAX_N = 1e5;
int n;
char s[MAX_N + 1];

bool solve(char *t) {
    for (int i = 1; i < n - 2; i++) {
        if (s[i] == 'x') {
            if (t[i] == 'S') {
                if (t[i - 1] == 'S') t[i + 1] = 'W';
                else t[i + 1] = 'S';
            }
            else {
                if (t[i - 1] == 'S') t[i + 1] = 'S';
                else t[i + 1] = 'W';
            }
        }
        else {
            if (t[i] == 'S') {
                if (t[i - 1] == 'S') t[i + 1] = 'S';
                else t[i + 1] = 'W';
            }
            else {
                if (t[i - 1] == 'S') t[i + 1] = 'W';
                else t[i + 1] = 'S';
            }
        }
    }

    if (s[n - 2] == 'x') {
        if (t[n - 2] == 'S' && t[n - 3] == t[n - 1]) return false;
        if (t[n - 2] == 'W' && t[n - 3] != t[n - 1]) return false;
    }
    else {
        if (t[n - 2] == 'S' && t[n - 3] != t[n - 1]) return false;
        if (t[n - 2] == 'W' && t[n - 3] == t[n - 1]) return false;
    }
    if (s[n - 1] == 'x') {
        if (t[n - 1] == 'S' && t[n - 2] == t[0]) return false;
        if (t[n - 1] == 'W' && t[n - 2] != t[0]) return false;
    }
    else {
        if (t[n - 1] == 'S' && t[n - 2] != t[0]) return false;
        if (t[n - 1] == 'W' && t[n - 2] == t[0]) return false;
    }
    return true;
}


int main() {
    scanf("%d", &n);
    scanf("%s", s);

    char ans[4][n + 1];
    for (int i = 0; i < 4; i++) ans[i][n] = 0;
    if (s[0] == 'x') {
        ans[0][0] = 'S'; ans[1][0] = 'S';
        ans[2][0] = 'W'; ans[3][0] = 'W';
    }
    else {
        ans[0][0] = 'W'; ans[1][0] = 'W';
        ans[2][0] = 'S'; ans[3][0] = 'S';
    }
    ans[0][1] = 'S'; ans[0][n - 1] = 'W';
    ans[1][1] = 'W'; ans[1][n - 1] = 'S';
    ans[2][1] = 'S'; ans[2][n - 1] = 'S';
    ans[3][1] = 'W'; ans[3][n - 1] = 'W';

    for (int i = 0; i < 4; i++) {
        if (solve(ans[i])) {
            printf("%s\n", ans[i]);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
