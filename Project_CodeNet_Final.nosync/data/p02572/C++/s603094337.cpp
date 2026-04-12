#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define time_taken_start int begtime = clock();
#define time_taken_end int endtime = clock(); \
cerr << "\n\n" << "Time elapsed: " << \
(endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
return 0;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define inf 100000000000000007
#define eps 0.000000000001
#define pi acosl(-1)
#define pdd pair<ld,ld>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpl vector<pll>
#define vll vector<ll>
#define mseti multiset <ll>
#define msetd multiset <ll,greater<ll>>
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound 
#define stp fixed<<setprecision(20)
#define endl '\n'
ll power(ll x,ll y)
{
    ll res=1;
  
    while(y>0)
    {
        if(y&1)
            res=res*x;
        res%=mod;
        y=y>>1;
        x=x*x;
        x%=mod;
    } 
    return res; 
}
ll inv(ll x)
{
    return power(x,mod-2);
}
void solve()
{
    ll n;
    ll x;
    cin>>n;
    ll sum=0;
    ll d=0;
    for(ll i=0;i<n;i++)
    {
        cin>>x;
        sum+=x;
        sum%=mod;
        d+=(x*x);
        d%=mod;
    }
    sum*=sum;
    sum%=mod;
    sum-=d;
    sum%=mod;
    sum+=mod;
    sum*=inv(2);
    sum%=mod;
    cout<<sum;

}
int main()
{
    FAST
    #ifdef ayk_16
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
    #endif
    time_taken_start
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++)
    {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    time_taken_end
}