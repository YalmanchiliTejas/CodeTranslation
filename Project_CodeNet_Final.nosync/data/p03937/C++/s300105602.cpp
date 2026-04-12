#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = 10;
char f[N][N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", f[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (f[i][j] == '#')
                cnt++;

    int xcnt = 1;
    int i = 0, j = 0;
    while (true)
    {
        if (f[i][j + 1] == '#')
        {
            xcnt++;
            j++;
        }
        else if (f[i + 1][j] == '#')
        {
            xcnt++;
            i++;
        }
        else
            break;
    }

    printf(cnt == xcnt ? "Possible\n" : "Impossible\n");


	return 0;
}


