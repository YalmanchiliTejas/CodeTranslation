#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef long long llong;
typedef pair<int, int> pii;

void solve() {

	const int pay = 800, refund = 200;

	int n;
	cin >> n;

	int total_paid = 800 * n;
	int total_refund = n / 15 * 200;

	int ans = total_paid - total_refund;

	cout << ans;

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifdef LOCAL
		ifstream in("in");
		cin.rdbuf(in.rdbuf());
	#endif

	solve();

	return 0;

}