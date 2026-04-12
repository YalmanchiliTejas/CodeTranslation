#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<long long,int>, null_type, less<pair<long long,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
 
#define f first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define all(num) num.begin(), num.end()
#define lp(i, nodess) for (int i = 0; i < nodess; i++)
#define mem(u, vis) memset(u, vis, sizeof(u))
#define Y imag()
#define angle(u) (atan2(u.Y, u.X))
#define vec(u, v) ((v) - (u))
//#define length(u) (hypot(u.Y , u.X))
#define normalize(u) (u) / length(u)
#define dotP(u, v) ((conj(u) * v).X)
#define crossP(u, v) ((conj(u) * v).Y)
#define same(p1, p2) (dotP(vec(p1, p2), vec(p1, p2)) < EPS)
#define lengthSqr(u) dotP(u, u)
#define rotate0(p, ang) ((p)*exp(point(0, ang)))
#define rotateA(p, ang, about) (rotate0(vec(about, p), ang) + about)
#define reflect0(vis, m) conj(vis / m) * m
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const double PI = acos(-1.0);
const double EPS = (1e-10);
const long long int INF = 0x3f3f3f3f;
long long mod = 998244353;
typedef long long int ll;
typedef unsigned long long ull;
typedef complex<double> point;
long long fastpow(ll nodess, ll num, ll m) {
  if (!num)
    return 1;
  if (num % 2)
    return nodess * fastpow(nodess, num - 1, m)%m;
  ll p = fastpow(nodess, num / 2, m);
  p %= m;
  p *= p;
  p %= m;
  return p;
}
 
ll my_mod(ll num, ll mod) {
  ll reto = num % mod;
  while (reto < 0)
    reto += mod;
  return reto;
}
 
ll gcd(ll u, ll v) { return !u ? v : gcd(v % u, u); }
/*long long dist(pair<ll, ll> u, pair<ll, ll> v) {
  return 
      abs(u.f - v.f)  + abs(u.se - v.se);
}*/
long long getDist(pair<ll, ll> &u, pair<ll, ll> &v) {
  return 
     (u.f - v.f)*(u.f - v.f)  + (u.se - v.se)*(u.se-v.se);
}
 
 
 
//vector<int> ap;
const int MX = 1e5 +9;
int np[MX+5];
void s(){
    mem(np , 1);
    np[1] = np[0] = 0;
    for(ll i = 2 ; i*i<= MX ;i++){
        if(np[i]){
            for(ll j= i*i ; j <=MX; j+=i) np[j] = 0;
        }
    }
   /* int idx = 1;
    for(ll i = 2 ; i<= MX ; i++){
        if(np[i]){
            np[i] = idx;
            idx++; 
            ap.pb(i);
        }
    }*/
    //cout<<idx;
}
 
#define int ll
ll fact[MX], ifact[MX];
ll ncr(ll n, ll r){
    ll ret = fact[n];
    ret *= ifact[r];
    ret %= mod;
    ret *= ifact[n-r];
    return ret%mod;
}
 
const int P1=31;
const int MOD1=1e9+7;
struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;

	Hashs() {}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--) 
		{
			hashs[i]=(1LL * hashs[i+1] * P + s[i] - 'a' + 1) % MOD;
			pows[n-i]=(1LL * pows[n-i-1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n-1] * P)%MOD;
	}
	int get_hash(int l, int r) 
	{
		if(l > r) {
			cout<<l<<"**"<<r<<"\n";
			swap(l,r);
		}
		int ans=hashs[l] + MOD - (1LL*hashs[r+1]*pows[r-l+1])%MOD;
		ans%=MOD;
		return ans;
	}
};
bool isp(string &s){
	int n = s.size();
	for(int i = 0 ;i  < n/2; i++){
		if(s[i] != s[n-1-i]) return 0;
	}
	return 1;
}

int n,ss;
vector<int> arr;
ll dp[3009][3009];

ll solve(int i, ll lef){
	if(lef == 0) return n - i + 1;
	if(i == n || lef < 0) return 0;
	ll &ret = dp[i][lef];
	if(~ret) return ret;
	ret = solve(i+1, lef);
	ret %= mod;
	ret += solve(i+1, lef - arr[i]);
	return ret%mod;
}
int32_t main(){
	IO;
	cin>>n>>ss;
	arr.resize(n);
	for(int i = 0 ; i < n; i++) cin>>arr[i];
	ll ans = 0;
	mem(dp, -1);
	for(int i = 0; i < n; i++){
		ll cp = i+1;
		if(arr[i] > ss) continue;
		ll ret = solve(i+1, ss-arr[i]);
		ret *= cp;
		ret %= mod;
		ans += ret;
		ans %= mod;
	}
	cout<<ans<<"\n";
	return 0;
}
