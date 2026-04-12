#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
#define mod 1000000007
#define inf (int)1e9+7
using namespace std;
ll  dp[10009][101][2][2];
string k; int d;
ll call(ll ind,ll m,bool check,bool suru)
{
    if(ind==-1) return m%d==0 and suru;
    ll limit=check?k[ind]-'0': 9;
    ll ans=0;
    ll &ret=dp[ind][m][check][suru];
    if(ret!=-1 ) return ret;
    for(ll i=0;i<=limit;i++)
    {
        bool ck=(i==k[ind]-'0')? check: false;
        int mm=(m+i)%d;
        ans+=call(ind-1,mm,ck,suru|i);
    }
    return ret=ans%mod;
}
int   main()
{
    memset(dp,-1,sizeof dp);
    cin>>k>>d;
    reverse(k.begin(),k.end());
    ll e=call(k.size()-1,0,1,0)%mod;
    cout<<e<<endl;
}
