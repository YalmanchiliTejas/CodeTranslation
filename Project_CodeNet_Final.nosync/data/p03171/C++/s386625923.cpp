#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
#define fi first
#define se second
const ll inf = 9e18;
const ll mod = 1e9 + 7;

void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;

        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }

ll dp[3005][3005];
ll a[3005];

ll f(int i, int j, ll sum){
	
	if(i==j-1){
		dp[i][j] = max(a[i], a[j]);
		return dp[i][j];
	}
	if(dp[i][j] == -1)
		dp[i][j] = max(sum-f(i+1, j, sum-a[i]), sum-f(i, j-1, sum-a[j]));
	return dp[i][j];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin>>n;
	ll sum = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = -1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<2*f(0, n-1, sum) - sum;
	return 0;
}


