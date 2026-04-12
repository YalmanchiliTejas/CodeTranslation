#include <bits/stdc++.h>
using namespace std;
#define N 110
int i,j,k,m,n,x,y,l[N],r[N];
char s[N][N];
inline void check(int*a,int n,int m,int f) {
    for (int i = 1, k, j; i <= n; ++i) {
        for (k = 0, j = 1; j <= m; ++j)if (f ? (s[i][j] == '.') : (s[j][i] == '.'))++k;
        if (k == m)a[i] = 1;
    }
}
int main() {
    for (scanf("%d%d", &n, &m), i = 1; i <= n; ++i)scanf("%s", s[i] + 1);
    check(l, n, m, 1), check(r, m, n, 0);
    for (i = 1; i <= n; ++i) {
        x = 0;
        for (j = 1; j <= m; ++j) {
            if (l[i] || r[j])continue;
            x = 1, putchar(s[i][j]);
        }
        if (x)puts("");
    }
}