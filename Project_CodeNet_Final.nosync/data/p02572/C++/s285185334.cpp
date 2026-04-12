#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define fi first
#define se second
#define upb upper_bound
#define lwb lower_bound
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y){
    if(y<=0) return 1;
    ll ans = 1;
    x %= mod;
    while(y){
        if(y&1)
            ans = (x * ans) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = (a - b); if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = (a + b); if(c >= mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

//------------------------------------------------------------------------------------------

//const ll N = 2e5 + 1;
//vector<ll> adj[N];
//bool visited[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);

	ll n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	ll pref[n] = {0};
	pref[0] = 0;
	for(int i=1;i<n;i++){
		pref[i] = add(pref[i-1], a[i-1]);
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ans = add(ans, mul(pref[i], a[i]));
	}
	cout<<ans;


    return 0;
}
