#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

#define f first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define all(x) x.begin(), x.end()
#define lp(i, n) for (int i = 0; i < n; i++)
#define mem(a, v) memset(a, v, sizeof(a))
#define X real()
#define Y imag()
#define angle(a) (atan2(a.Y, a.X))
#define vec(a, b) ((b) - (a))
//#define length(a) (hypot(a.Y , a.X))
#define normalize(a) (a) / length(a)
#define dotP(a, b) ((conj(a) * b).X)
#define crossP(a, b) ((conj(a) * b).Y)
#define same(p1, p2) (dotP(vec(p1, p2), vec(p1, p2)) < EPS)
#define lengthSqr(a) dotP(a, a)
#define rotate0(p, ang) ((p)*exp(point(0, ang)))
#define rotateA(p, ang, about) (rotate0(vec(about, p), ang) + about)
#define reflect0(v, m) conj(v / m) * m
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const double PI = acos(-1.0);
const double EPS = (1e-10);
const long long int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
typedef long long int ll;
typedef unsigned long long ull;
typedef complex<double> point;
long long fastpow(ll n, ll x) {
  if (!x)
    return 1;
  if (x % 2)
    return n * fastpow(n, x - 1);
  ll p = fastpow(n, x / 2);
  p %= mod;
  p *= p;
  p %= mod;
  return p;
}

ll my_mod(ll num, ll mod) {
  ll ret = num % mod;
  while (ret < 0)
    ret += mod;
  return ret;
}

ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
long double dist(pair<ll, ll> &a, pair<ll, ll> &b) {
  return sqrt(
      ((a.f - b.f) * (a.f - b.f) * 1.0 + (a.se - b.se) * (a.se - b.se)));
}
/*vector<int> ap;
bool np[MX];
void s(){
    mem(np , 1);
    np[1] = np[0] = 0;
    for(ll i = 2 ; i*i<= MX ;i++){
        if(np[i]){
            for(ll j= i*i ; j <MX; j+=i) np[j] = 0;
        }
    }
    for(ll i = 2 ; i< MX ; i++) if(np[i]) ap.pb(i);
}*/
const ll MX = 1e5+5;
vector<int> arr(3005);    
ll dp[3005][3005][2];
int n;
ll solve(int l , int r,bool turn){
	if(l > r) return 0;
	ll &ret = dp[l][r][turn];
	if(~ret) return ret;
	if(turn)ret = max(solve(l+1,r,!turn) + arr[l] , solve(l,r-1,!turn) + arr[r]);
	else ret = min(solve(l+1,r,!turn) - arr[l] , solve(l,r-1,!turn) - arr[r]);
	return ret;
}
int main()
{
    IO;
    cin>>n;
    ll s= 0;
    for(int i = 0 ;i<n ;i++){
		 cin>>arr[i];
		s+=arr[i];
	}
	mem(dp,-1);
	cout<<solve(0,n-1,1);
    return 0;
}

