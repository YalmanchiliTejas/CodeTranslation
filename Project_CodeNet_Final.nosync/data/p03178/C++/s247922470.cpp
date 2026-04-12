#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;

typedef long long ll;

const ll mod = 1e9 + 7;

ll dp[maxn][105][2];

char s[maxn];
int n;

int d;

ll solve(int pos, int m, int tight)
{
    if(pos == n)
    {
        return m == 0;
    }
    ll &ans = dp[pos][m][tight];
    if(ans != -1)
        return ans;
    ans = 0;
    int lim = 9;
    if(tight)
        lim = s[pos] - '0';
    for(int i = 0; i <= lim; i++)
    {
        ans = (ans + solve(pos+1, (m+i) % d, tight && (s[pos] - '0') == i) ) % mod;
    }
    return ans;
}

int main()
{
    scanf("%s",s);
    scanf("%d",&d);
    n = strlen(s);
    //reverse(s,s+n);

    memset(dp,-1,sizeof(dp));
    printf("%lld\n",(solve(0,0,1) - 1 + mod) % mod );
    return 0;
}