/*
ID: toooooEasy or RafaelSaddatimov
PROG:
*/
#include <bits/stdc++.h>
#define MAX 101
#define MOD 1000000LL
#define INF 1000000000
#define EPS 1e-12
#define ll long long
using namespace std;

int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    int res = r * 100 + g * 10 + b;
    if(res % 4 == 0)
        printf("YES");
    else
        printf("NO");
}
