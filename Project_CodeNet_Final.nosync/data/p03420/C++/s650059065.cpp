#include "bits/stdc++.h"
#include <queue>

#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef long long ll;



void solve() {
	int n, K;
	cin >> n >> K;

	ll ans = 0;
	FOR(b, K + 1, n) {
		ans += (n / b) * (b - K);
		ans += max(0, n % b - K + 1);
		if (K == 0) ans -= 1;
	}
	cout << ans << endl;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve(); 
	return 0;
}