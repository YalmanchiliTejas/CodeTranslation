#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(100);
}

#define int ll
ll comb(int a, int b) {
	if (a < b) return 0;
	ll ans = 1;
	REP(i, b) {
		ans *= a - i;
		ans /= i + 1LL;
	}
	return ans;
}

void solve(){
	string n;
	int k;
	cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i < n.length(); ++i) {
		if (n[i] != '0') {
			//n[i] = '0'の場合
			ans += comb(n.length() - i - 1, k) * pow(9LL, k);
			//not 0
			k--;
			if (k == -1) {
				break;
			}
			ans += comb(n.length() - i - 1, k) * pow(9LL, k) * (long long)(n[i] - '1');
		}
	}
	if (k == 0) {
		ans++;
	}
	cout << ans << endl;
}
#undef int
int main() {
	init();
	solve();
}