#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=200010;

vector<ll> ar;
ll k;
ll dp[10001][2][101];
ll func(ll idx,ll t,ll m)
{
    if(idx<0){
        if(m==0){return 1;}
        return 0;
    }
    if(dp[idx][t][m]==-1){
    ll ans=0;
    ll kk=t==1?ar[idx]:9;
    for(ll i=0;i<=kk;++i)
    {
        ll nt=t&(i==ar[idx]);
        ans=(ans+func(idx-1,nt,(m+i)%k))%M;
    }
    dp[idx][t][m]=ans;
    }
    return dp[idx][t][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    cin>>k;
    for(ll i=0;i<s.length();++i)
    {
        ar.pb(s[i]-'0');
    }
    ll n=ar.size();
    reverse(ar.begin(),ar.end());
    memset(dp,-1,sizeof(dp));
    ll ans=(func(n-1,1,0)-1+M)%M;

    cout<<ans<<endl;

    return (0);
}
