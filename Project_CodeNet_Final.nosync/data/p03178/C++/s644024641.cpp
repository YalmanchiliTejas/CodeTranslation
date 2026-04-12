//Patwari26
#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define endl        '\n'
#define mii         map<ll,ll>
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
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
ll m,n,k;
string s,t;
ll dp[N][105][2];
int digitdp(int index,int rem,int tight) // backup code
{
  if(index==sz(t))
  {
    if(rem==0)return 1;
    return 0;
  }
  if(dp[index][rem][tight]!=-1)return dp[index][rem][tight];
  int limit=(tight)?(t[index]-'0'):9;
  int ans=0;
  rep(d,0,limit)
  {
    int ct=0;
    if(d==(t[index]-'0'))ct=tight;
    ans=(ans+digitdp(index+1,(rem+d)%k,ct))%hell;
  }
  return dp[index][rem][tight]=ans;
}
void solve(){
    // ll k,d;
    cin>>t>>k;
    memset(dp,-1,sizeof(dp));
    ll curr=digitdp(0,0,1);
    curr=(curr-1+hell)%hell;
    cout<<curr;
    // while(k!=0){

    // }

}
signed main()
{
    ios
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
        solve();
    }
    time
    return 0;
}