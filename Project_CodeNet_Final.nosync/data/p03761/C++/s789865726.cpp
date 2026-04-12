#include <cstdio>

#define maxn 50

int f[maxn + 1]['z' - 'a' + 1];
int main() {
    int n;
    scanf("%d", &n);
    for (int j = 1; j <= 'z' - 'a' + 1; j++) {
           f[0][j] = maxn * maxn + 1;
    }
    char ch = fgetc(stdin);
    for (int i = 1; i <= n; i++) {
        ch = fgetc(stdin);
        while (ch != '\n') {
            f[i][ch - 'a' + 1]++;
            ch = fgetc(stdin);
        }
        for (int j = 1; j <= 'z' - 'a' + 1; j++) {
            if (f[i][j] < f[0][j])
                f[0][j] = f[i][j];
        }
    }
    for (int j = 1; j <= 'z' - 'a' + 1; j++) {
        while (f[0][j] > 0) {
            ch = 'a' + j - 1;
            printf("%c", ch);
            f[0][j]--;
        }
    }

    printf("\n");
    return 0;
}
