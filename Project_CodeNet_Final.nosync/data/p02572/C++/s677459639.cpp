#include <bits/stdc++.h>

#define mp make_pair
#define eb emplace_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#ifdef ONPC
mt19937 rnd(228);
#else
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif

const int MAXN = 100;
//#define int long long
const int INF = 1e9;

int MOD = 1e9 + 7;
int add(int a, int b){
	return (a + b) % MOD;
}

int mul(int a, int b){
	return ((ll)a * (ll)b) % (ll)MOD;
}


void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int  i = 0; i < n; i++) cin >> a[i];

	int s = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = add(ans, mul(s, a[i]));
		s = add(s, a[i]);
	}

	cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

		solve();

    return 0;
}
