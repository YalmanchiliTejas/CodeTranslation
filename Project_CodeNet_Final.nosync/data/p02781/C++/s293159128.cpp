#include <bits/stdc++.h>
using namespace std;
#define _for(i,a,b) for(int i = (a);i <= (b);++i)
#define LOCAL
typedef long long ll;
const int maxn = 105;
int num[maxn],k;
string a;
ll dp[maxn][4];
ll dfs(int pos,int now,bool limit){
    if(pos==-1)return now==k;
    if(!limit&&dp[pos][now]!=-1)return dp[pos][now];
    int up = limit?num[pos]:9;
    ll ans = 0;
    for(int i = 0;i <= up;++i)
    {
        if(i==0)
        {
            ans+=dfs(pos-1,now,limit&&i==up);
        }
        else if(now<k){
            ans+=dfs(pos-1,now+1,limit&&i==up);
        }
    }
    if(!limit)dp[pos][now]=ans;
    return ans;
}
int main()
{
#ifdef LOCALa
    freopen("simple.in","r",stdin);
    freopen("simple.out","w",stdout);
#endif
    memset(dp,-1,sizeof(dp));
    cin>>a>>k;
    for(int i = 0;i < a.size();++i)
        num[i]=a[i]-'0';
    reverse(num,num+a.size());
    cout<<dfs(a.size()-1,0,1)<<endl;
    return 0;
}