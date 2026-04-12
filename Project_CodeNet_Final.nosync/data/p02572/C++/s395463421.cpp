/********************************************//**
 ****** Handle: techno_phyle    *****************
 ***********************************************/

#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
#define mod 1000000007
#define N 100010
#define M 200010
#define db(a) cout << a << endl
#define db2(a,b) cout << a << " " << b << endl
#define dbp(a) cout << a.first << " " << a.second << endl
#define adb(a) for(auto it:a) cout << it << " "; cout << endl
#define adbp(a) for(auto it:a) cout << it.first << " " << it.second << endl
#define pb push_back
#define mp make_pair
#define endline "\n"
#define in(x) scanf("%d",&x);
const ll INF = 1e18L + 5;
const int inf = 1e9 + 5;
typedef pair<double, long> key;
struct comp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		if (p1.first < p2.first) return false;
		if (p2.first < p1.first) return true;
		return p1.second < p2.second;
	};
};

int main() {
	fastIO;
	int test = 1 , j = 1;
	//cin >> test;
	while (test--) {
		int n;
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		ll pref[n];
		pref[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; i--) pref[i] = pref[i + 1] + a[i];
		ll ans = 0;
		for (int i = 0; i < n - 1; i++) {
			ll val = ((a[i] % mod) * (pref[i + 1] % mod)) % mod;
			ans = (ans + val) % mod;
		}
		cout << ans << endl;

	}
	return 0;
}



