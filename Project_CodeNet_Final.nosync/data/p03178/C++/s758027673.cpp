#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"----------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
vector<ll >v;
int d;
ll dp[10009][2][105];
ll call(ll ind, bool check,ll sum)
{
    if(ind==-1) return sum==0;
    ll cnt=0;
    ll limit=check? (v[ind]):9;
    ll &ret=dp[ind][check][sum];
    if(ret!=-1 and !check) return ret;
    for(ll i=0;i<=limit;i++)
    {
        bool ck=(i==v[ind])? check:0;
        cnt+=call(ind-1,ck,(sum+i)%d);
        cnt%=mod  ;
    }
    if(!check) ret=cnt; ///is used so that we can call this function without memset for another query
    return cnt;
}
ll  get(string x)
{
    for(int i=x.size()-1;i>=0;i--) v.pb(x[i]-'0');

    return call((int)v.size()-1,1,0);
}
int  main()
{
    memset(dp,-1,sizeof dp);
    string a;
    cin>>a>>d;
    ll ans=get(a)-1;
    ans=(ans+mod)%mod ;
    cout<<ans<<endl;
}
