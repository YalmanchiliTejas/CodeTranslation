#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

ll lay[60];

ll ans(int n, ll x) {
	if (x == 0)return 0;
	if (n == 0)return 1;

	if (x <= lay[n - 1] + 1)return ans(n - 1, x - 1);
	if (x == lay[n - 1] + 2)return ans(n - 1, lay[n - 1]) + 1;
	if (x <= lay[n - 1] * 2 + 2)return ans(n - 1, lay[n - 1]) + 1 + ans(n - 1, x - (lay[n - 1] + 2));
	return 2* ans(n - 1, lay[n - 1]) + 1;
}



int main() {

	ll n, x;
	cin >> n >> x;
	lay[0] = 1;
	rep1(i, n)lay[i] = 2 * lay[i - 1] + 3;

	cout << ans(n,x) << endl;
}