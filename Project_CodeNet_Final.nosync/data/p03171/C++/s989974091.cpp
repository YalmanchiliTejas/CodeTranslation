#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 25, M = 1e6 + 25, oo = 1e9, mod = 1e9 + 7;
const long long OO = 1e18+25;

int n, a[N];
long  long  mem[N][N][2];

long long dp(int i=0, int j=n-1, int turn=1)
{
    if(i > j) return 0;
    long long &ret = mem[i][j][(turn==1)];
    if(ret != 0) return ret;
    if(turn==1)return ret = max(dp(i+1,j, turn*-1)+(turn*a[i]), dp(i, j-1, turn*-1)+(a[j]*turn));
    return ret = min(dp(i+1,j, turn*-1)+(turn*a[i]), dp(i, j-1, turn*-1)+(a[j]*turn));
}

int main()
{
    //memset(mem, -1, sizeof mem);
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",a+i);
    printf("%lld",dp());
    return 0;
}