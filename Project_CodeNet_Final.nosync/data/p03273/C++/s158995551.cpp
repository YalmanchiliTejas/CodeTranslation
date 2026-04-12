#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 110;
int n, m;
char a[N][N];
bool row[N], col[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            a[i][j] = getchar();
            while (a[i][j] != '.' && a[i][j] != '#') a[i][j] = getchar();
        }
    for (int i = 1; i <= n; i++){
        bool fl = 1;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#'){
                fl = 0;
                break;
            }
        row[i] = fl;
    }
    for (int i = 1; i <= m; i++){
        bool fl = 1;
        for (int j = 1; j <= n; j++)
            if (a[j][i] == '#'){
                fl = 0;
                break;
            }
        col[i] = fl;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            if (!row[i] && !col[j])
                putchar(a[i][j]);
        if (!row[i]) putchar('\n');
    }
    return 0;
}