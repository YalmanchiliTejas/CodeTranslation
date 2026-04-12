#include <bits/stdc++.h>

//#define fin cin
//#define fout cout

#define leftSon (node << 1)
#define rightSon ((node << 1) | 1)

#define pii pair < int , int >
#define F first
#define S second

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const long long infL = LLONG_MAX;

const int nmax = 10;

int n, m, i, j;
char a[nmax][nmax];

bool used[nmax][nmax];

void print_answer(int x) {
    if (!x) printf("Impossible\n");
    else printf("Possible\n");

    exit(0);
}

void go(int x, int y) {
    used[x][y] = 1;

    if (x < n && a[x+1][y] == '#') {
        go(x + 1, y);
        return;
    }

    if (y < m && a[x][y+1] == '#') {
        go(x, y + 1);
        return;
    }
}

int main()
{
 

    /*
    ifstream fin("input.in");
    ofstream fout("output.out");
    */

    scanf("%d %d\n", &n, &m);
    for (i = 1; i <= n; ++i, scanf("\n"))
        for (j = 1; j <= m; ++j)
            scanf("%c", &a[i][j]);

    if (a[1][1] == '.')
        print_answer(0);

    go(1, 1);

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            if (!used[i][j] && a[i][j] == '#')
                print_answer(0);

    print_answer(1);

    return 0;
}
