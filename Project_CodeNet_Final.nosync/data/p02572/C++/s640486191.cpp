#include <bits/stdc++.h>
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp make_pair
#define sz(x) ((int)(x).size())
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(),x.end()
#define y1 omg
#define INF 1000000010
#define FOR(x, n) for(int x=0; x<n; x++)
#define ini(x, n) memset(x, n, sizeof(x));
#define MOD ((int)1e9 + 7)
#define atoi(x) ((x)-'0')
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

const int MAX = 2e5 + 1;
int n, arr[MAX], sum[MAX], ans;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = (arr[i] + sum[i - 1]) % MOD;
	}
	for (int i = 1; i < n; i++) {
		ans += (arr[i] * (sum[n] - sum[i] + MOD)) % MOD;
		ans %= MOD;
	}
	cout << ans;
}