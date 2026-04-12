#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mod 10000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"----------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
vector<ll >v;
void convert(string b)
{
    v.clear();
    for(ll  i=b.size()-1;i>=0;i--)
    {
        v.pb(b[i]-'0');
    }

}
ll dp[109][2][109];
ll  k;
ll call(ll ind, bool check,ll sum)
{
    if(ind==-1) return sum==k;
    ll cnt=0;
    ll limit=check? (v[ind]):9;
    ll &ret=dp[ind][check][sum];
    if(ret!=-1 and !check) return ret;
    for(ll i=0;i<=limit;i++)
    {
        bool ck=(i==v[ind])? check:0;
        cnt+=call(ind-1,ck,sum+bool(i));
    }
    if(!check) ret=cnt;
    return cnt;
}
int  main()
{
    string b;
    memset(dp,-1,sizeof dp);
    cin>>b>>k;
    convert(b);
    ll ans1=call(v.size()-1,1,0);
    cout<<ans1<<endl;
}
