#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define int long long
#define gcd __gcd
const int inf = 0x3f3f3f3f;
const int maxn = 210;
const int M = 1e9+7;
int n,m,k;

char s[maxn+1];
int a[maxn];
int dp[maxn][4];

int dfs(int bit,int gs,bool limit)
{   
    if(gs > k) return 0;
    if(bit == n)
    {
        if(gs == k) return 1;
        else return 0;
    }
    if(!limit && dp[bit][gs]) return dp[bit][gs];
    int up = limit?a[bit]:9;
    int ans = 0;
    for(int i = 0; i <= up; i++)
    {
        ans += dfs(bit+1,gs + (i!=0), limit && i == a[bit]);
    }
    if(!limit) dp[bit][gs] = ans;
    return ans;
}

signed main()
{
    scanf("%s",s+1);
    cin>>k;
    for(n = 1; s[n]; n++) 
    {
        a[n] = s[n] - '0';
    }
    int ans = dfs(0,0,1);
    cout<<ans<<endl;
    return 0;
}