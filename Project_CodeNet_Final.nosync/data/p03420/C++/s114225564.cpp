#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, K; cin >> N >> K;
	ll ans = 0;

	for (ll i = K + 1; i <= N; i++) {
		ll quo = N / i;
		ll rem = N % i;

		ll cnt = quo * (i - K);
		if (K != 0) cnt += max(0LL, rem - K + 1);
		else cnt += rem;

		//cout << i << " : " << cnt << endl;
		ans += cnt;
	}

	cout << ans << endl;

	return 0;
}