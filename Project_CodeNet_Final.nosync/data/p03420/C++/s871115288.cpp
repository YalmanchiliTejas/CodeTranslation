#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {
	int n,k;
	cin >> n >> k;

	ll ans = 0;


	if (k > 0) {
		for (int b = k + 1;b <= n;b++) {
			ans += ((ll)b - k) * (n / b) + max((n % b) - k + 1, 0);
		}
	}
	else ans = (ll)n * n;

	cout << ans << endl;

}