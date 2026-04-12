#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592;
const int MAX_N = 1e5+5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

const bool dbgEnabled = false;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef pair<string, ll> psi;
typedef pair<ll, string> pis;
typedef vector<pii> vpii;
typedef vector<psi> vpsi;
typedef vector<pis> vpis;
typedef vector<vi> vvi;

// Debug macros
#define dbg(x) do { \
	if (dbgEnabled) { cerr << #x << ": " << x << "\n"; } \
} while (0)

#define dbgv(x) do { \
	if (dbgEnabled) { cerr << #x << ": [ "; for (auto& _ : x) cerr << _ << " "; cerr << "]\n"; } \
} while (0)

#define dbgvv(x) do { \
	if (dbgEnabled) { cerr << #x << ":\n[\n"; for (auto& __ : x) dbgv(__); cerr << "]\n";} \
} while (0)

void solve() {
	ll n; cin >> n;
	vi a(n); for (auto &x : a) cin >> x;
	ll suffixSum = a[n-1];
	ll res = 0;
	for (ll i = n-2; i >= 0; i--) {
		res = (res + ((a[i] * suffixSum)%MOD))%MOD;
		suffixSum = (suffixSum + a[i])%MOD;
	}
	cout << res << endl;
}

int main() {
	if (!dbgEnabled) {
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr); cout.tie(nullptr);
	}
	
	ll t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}    
    return 0;
}

