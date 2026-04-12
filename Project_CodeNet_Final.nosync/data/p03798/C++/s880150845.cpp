#include <cstdio>

#define maxn 100000
#define ll long long

char com (char a) {
    if (a == 'S')
        return 'W';
    else
        return 'S';
}
inline int check (char a, char b, int n, char f[]) {
    char start1 = a;
    char start2 = b;
    char c;
    for (int i = 3; i <= n + 2; i++) {
        if (b == 'S' && f[i - 1] == 'o')
            c = a;
        if (b == 'S' && f[i - 1] == 'x')
            c = com(a);
        if (b == 'W' && f[i - 1] == 'o')
            c = com(a);
        if (b == 'W' && f[i - 1] == 'x')
            c = a;
        a = b;
        b = c;
    }
    if (a == start1 && b == start2)
        return 1;
    return 0;
}
inline void afisare(char a, char b, int n, char f[]) {
    char c;
    printf("%c%c", a, b);
    for (int i = 3; i <= n; i++) {
        if (b == 'S' && f[i - 1] == 'o')
            c = a;
        if (b == 'S' && f[i - 1] == 'x')
            c = com(a);
        if (b == 'W' && f[i - 1] == 'o')
            c = com(a);
        if (b == 'W' && f[i - 1] == 'x')
            c = a;
        printf("%c", c);
        a = b;
        b = c;
    }
}
char f[maxn + 2];

int main() {
    int n;
    scanf("%d", &n);
    char x = fgetc(stdin);
    for (int i = 1; i <= n; i++)
        f[i] = fgetc(stdin);
    f[n + 1] = f[1];
    char d1[] = {'S', 'W', 'S', 'W'};
    char d2[] = {'S', 'W', 'W', 'S'};
    int rep = 0;
    for (int i = 0; i <= 3 && rep == 0; i++) {
        rep = check(d1[i], d2[i], n, f);
        if (rep == 1)
            afisare(d1[i], d2[i], n, f);
    }
    if (rep == 0)
        printf("-1");
    return 0;
}
