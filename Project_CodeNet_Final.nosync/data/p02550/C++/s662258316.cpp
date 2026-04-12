//Patwari26
//#include template<t> as mine
#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define endl        '\n'
#define mii         map<ll,ll>
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (ll)x.size()
#define hell        1000000007
#define INF         (1ll<<60)
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define rrep(i,a,b)  for(ll i=a;i>=b;i--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int N=100005;
void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    ll curr=x;
    ll ans[m];
    ll zz=0;
    ll tot=0;
    memset(ans,0,sizeof(ans));
    ll i=0;
    for(i=1;i<=m+1;i++){
        if(ans[curr]!=0) break;
        if(zz==n) break;
        zz++;
        tot+=curr;
        ans[curr]=i;
        curr=(curr*curr)%m;
    }
    if(zz==n){
        cout<<tot<<endl;
        return;
    }
    // cout<<curr<<" ";
    ll idx=curr;
    ll cc=0;
    ll totnew=0;
    for(i=1;i<=m+1;i++){
        if(zz==n) break;
        zz++;
        tot+=curr;
        totnew+=curr;
        cc++;
        curr=(curr*curr)%m;
        if(curr==idx) break;
    }
    if(zz==n){
        cout<<tot<<endl;
        return;
    }
    ll left=(n-zz);
    tot+=(left/cc)*totnew;
    left=left%cc;
    zz=0;
    for(i=1;i<=m+1;i++){
        if(zz==left) break;
        zz++;
        tot+=curr;
        curr=(curr*curr)%m;
    }
    cout<<tot<<endl;

}
signed main()
{
    ios
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
        solve();
    }
    // time
    return 0;
}