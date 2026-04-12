#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> arr;
typedef vector<arr> matrix;
typedef vector<ll> longarr;
typedef vector<longarr> longmat;
typedef map<int, arr> graph;
typedef vector<char> chararr;
typedef vector<chararr> charmat;
typedef pair<int, int> fraction;
ll MOD = 1000000007;
int n;
ll ar[3000];
ll dp[3000][3000][2];

ll fun(int i, int j, int turn) {
	if (i > j) return 0;
	ll &ans = dp[i][j][turn];
	if (ans != -1) return ans;
	if (turn == 0) ans = min(fun(i + 1, j, 1), fun(i, j - 1, 1));
	else ans = max(ar[i] + fun(i + 1, j, 0), ar[j] + fun(i, j - 1, 0));
	return ans;
}
int main() {

	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
		sum += ar[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << (2 * (fun(0, n - 1, 1)) - sum);

}