#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

vector<ll> ar;
ll dp[110][2][5];

ll func(ll idx,ll t,ll k)
{
    if(idx<0){
        if(k==0){return 1;}
        else{return 0;}
    }
    if(dp[idx][t][k]==-1){
    ll ans=0;
    int x=t==1?ar[idx]:9;
    for(int i=0;i<=x;++i)
    {
        int nt=t&(i==ar[idx]);
        if(i==0){
            ans+=func(idx-1,nt,k);
        }
        else{
            if(k>0){
                ans+=func(idx-1,nt,k-1);
            }
        }
    }
    dp[idx][t][k]=ans;}
    return dp[idx][t][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    cin>>n;
    ll k;
    cin>>k;
    for(ll i=0;i<n.length();++i)
    {
        ar.pb(n[i]-'0');
    }
    reverse(ar.begin(),ar.end());
    ll nn=ar.size();
    memset(dp,-1,sizeof(dp));
    ll ans=func(nn-1,1,k);
    cout<<ans<<endl;

    return (0);
}
