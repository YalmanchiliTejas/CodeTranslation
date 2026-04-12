/**
 *COYG, 14 FA Cups we are back baby
 */
#include <bits/stdc++.h>
using namespace std;
#define ll 		long long
#define mp 		make_pair
#define pb 		push_back
#define forn(i,n) 	for(int i=0;i<n;i++)
#define for1(i,n) 	for(int i=1;i<n;i++)
#define ford(i,n) 	for(int i=n-1;i>=0;i--)
#define vi 		vector<int>
#define vl 		vector<ll>
#define pii 		pair<int,int>
#define pll 		pair<ll,ll>
#define vpi 		vector<pair<int,int> >
#define vpl		vector<pair<ll,ll> >
#define vvi 		vector<vector<int> >
#define vvl 		vector<vector<ll> >
#define ull 		unsigned long long
#define IOS 		ios_base::sync_with_stdio(false);
#define PI 		3.1415926535897932384626
#define ff 		first
#define ss 		second
#define char2Int(c) 	(c-'0')
#define FOREACH(i,t) 	for (auto i=t.begin(); i!=t.end(); i++)
#define clr(a,x) 	memset(a,x,sizeof(a)) //set elements of array to some value
#define all(x)		(x).begin(),(x).end()//cout<<"Case #"<<zzz<<": ";
#define plll pair<ll,pll >
const ll mod=1000000007;
string s;ll d;ll n;
ll dp[10001][100][2];
ll getans(ll index,ll rem,ll maxval)
{
    if(index>=n){if(rem==0)return 1;else return 0;}
    if(dp[index][rem][maxval]!=-1)return dp[index][rem][maxval];
    ll ans=0;
    if(maxval)
    {
        forn(i,10)
        {
            ll temp=rem-i;
            if(temp<0)temp+=100*d;
            temp%=d;
            ans=(ans+getans(index+1,temp,1))%mod;
        }
    }
    else
    {
        ll val=char2Int(s[index]);
        forn(i,val)
        {
            ll temp=rem-i;
            temp=(temp+d)%d;
            ans=(ans+getans(index+1,temp,1))%mod;
        }
        ll nxt=rem-val;nxt=(nxt+d)%d;
        ans=(ans+getans(index+1,nxt,0))%mod;
    }
    dp[index][rem][maxval]=ans;
    return ans;
}
void solve()
{
    //dp[index][D][maxval(0/1)]
    cin>>s;cin>>d;n=(ll)s.size();
    forn(i,n)forn(j,d){dp[i][j][0]=-1;dp[i][j][1]=-1;}
    ll ret=getans(0,0,0);--ret;
    if(ret==-1)ret=mod-1;
    cout<<ret<<endl;
}
int main()
{
    IOS;cin.tie(NULL);
    ll zz;zz=1;
    //cin>>zz;
    for(int zzz=1;zzz<=zz;zzz++)
    {
        solve();
    }
    return 0;
}
