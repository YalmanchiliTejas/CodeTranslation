#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define y1 y_1
#define x1 y_2
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 2e5 + 20;
const int M = 1e6 + 2;
const int mod = 1e9 + 7;
const int inf = 2e9 + 3;
const ll INF = 1e16;

void data() {
	#ifdef PC
		freopen("main.in", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
}

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int n;
ll a[N];

int main() {
	data();
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	ll now = 0;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += (a[i] * now) % mod;
		ans %= mod;
		now += a[i];
		now %= mod;
	}
	cout << ans;
}