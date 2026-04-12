
#include<bits/stdc++.h>
using namespace std;
#define ll                          long long
#define in(a)                       ll a; cin>>a;
#define in2(a,b)                    ll a,b; cin>>a>>b;
#define in3(a,b,c)                  ll a,b,c; cin>>a>>b>>c;
#define in4(a,b,c,d)                ll a,b,c,d; cin>>a>>b>>c>>d;
#define in5(a,b,c,d,e)              ll a,b,c,d,e; cin>>a>>b>>c>>d>>e;
#define lelo(b)                     for(auto &i:b)cin>>i;
#define ff                          first
#define ss                          second
#define call(v)                     v.begin(),v.end()
#define rall(v)                     v.rbegin(),v.rend()
#define show(x)                     for(auto t:x)cout<<t<<" ";
#define pb                          push_back
#define bhar(s,v)                   memset(s,v,sizeof(s))
#define endl                        "\n"                       
#define ce(x)                       cout<<x<<"\n";
#define nl                          cout<<endl;
#define jaldi                       ios_base::sync_with_stdio(false);cin.tie(NULL);
#define dekh_lo                     ce("dekh_lo");
#define sz(x)                       (ll)x.size()
#define re                          return

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef pair<ll,ll> pii;
typedef vector<pii> vii;
typedef vector<ll> vi;

const ll mod=1e9+7;
const ll N=4e5+5;

/*


*/

void solve(){
	in(n);
	vi a(n); lelo(a);
	vi dp(n+1,0);
	for(ll i=0;i<n;i++){
		dp[i+1]=(dp[i]+a[i])%mod;
	}
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll sum=(dp[n]-dp[i+1]+mod)%mod;
		sum=(sum*a[i])%mod;
		ans=(ans+sum)%mod;
	}
	ce(ans%mod);
}

int32_t main(){
    // jaldi
    ll t; 
    // cin>>t;
    t=1;     
    while(t--){
        solve();
    }
}

/*


*/

  