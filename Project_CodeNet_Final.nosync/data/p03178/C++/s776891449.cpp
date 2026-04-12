#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 25, M = 1e6 + 25, oo = 1e9, mod = 1e9 + 7;
const long long OO = 1e18+25;

#define par pair<pair<int,int>, int>
#define f first
#define s second

int D, mem[N][100][10][2][2];
char k[N];

int dp(int idx=0, int m=0, int d=0, int b=1, int f=0)
{
    if(!k[idx] && m ==0 && f) return 1;
    if(!k[idx]) return 0;
    int &ret = mem[idx][m][d][b][f];
    if(~ret) return ret;
    ret = 0;
    if(d) f=1;
    int e = 9;
    if(b) e = int(k[idx]-'0');
    int nxtb = 0;
    if(b && d==e) nxtb = 1;
    return ret = (dp(idx+1, (m+(d%D))%D,0, nxtb,f) + (d<e?dp(idx,m,d+1,b,f):0))%mod;
}

int main()
{
    memset(mem, -1, sizeof mem);
    scanf("%s%d",k,&D);
    printf("%d",dp());
    return 0;
}