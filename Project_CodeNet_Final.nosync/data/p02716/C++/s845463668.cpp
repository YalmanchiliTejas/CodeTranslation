#include<bits/stdc++.h>
#define ll long long
#define inf 100000000000000000ll
using namespace std;
int n;
ll mem[200005][3], ara[200005];
bool vis[200005][3];
ll dp(int pos, int skip)
{
    if(pos>=n || (pos==n-1 && skip==2))return 0;
    if(vis[pos][skip])return mem[pos][skip];
    vis[pos][skip]= 1;
    mem[pos][skip]= -inf;
    if(skip)mem[pos][skip]= dp(pos+1, skip-1);
    mem[pos][skip]= max(mem[pos][skip], ara[pos]+dp(pos+2, skip));
    return mem[pos][skip];
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%lld", &ara[i]);
    ll res= -inf;
    if(!(n&1))
    {
        //memset(vis, 0, sizeof vis);
        res= max(res, ara[0]+dp(2, 1));
        //memset(vis, 0, sizeof vis);
        res= max(res, ara[1]+dp(3, 0));
    }
    else
    {
        //memset(vis, 0, sizeof vis);
        res= max(res, ara[0]+dp(2, 2));
        //memset(vis, 0, sizeof vis);
        res= max(res, ara[1]+dp(3, 1));
        //memset(vis, 0, sizeof vis);
        res= max(res, ara[2]+dp(4, 0));
    }
    printf("%lld\n", res);
    return 0;
}
