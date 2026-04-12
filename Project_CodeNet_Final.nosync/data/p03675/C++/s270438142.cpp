#include <bits/stdc++.h>

using namespace std;

//#define FILE_IO

int N;
int v[200005];

int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &v[i]);

    for(int i = N; i >= 1; i -= 2)
        printf("%d ", v[i]);
    for(int i = 1 + (N & 1); i <= N; i += 2)
        printf("%d ", v[i]);

    return 0;
}
