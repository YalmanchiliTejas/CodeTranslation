#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

void solve() {

	ll n;
	cin >> n;
	ll a[n];
	vl p(n+1,0);
	for(ll i = 0;i < n;i++){
		cin >> a[i];
		p[i] = a[i];
	}
	for(ll i = 1;i < n;i++){
		p[i]+=p[i-1];
		p[i]%=mod;
	}

	ll total = p[n-1];
	ll ans = 0;

	for(ll i = 0;i < n-1;i++){
		ans += (((total - p[i])%mod+mod)%mod)*a[i];
		ans%=mod;
	}
	cout << ans << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
