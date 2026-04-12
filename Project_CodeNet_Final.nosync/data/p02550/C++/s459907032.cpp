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
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

const int MAX = 1e5;
int n, idx, x, m, sum, dp_sum[MAX], dp_idx[MAX];

signed main() {
	ini(dp_sum, -1);
	ini(dp_idx, -1);
	cin >> n >> x >> m;
	for (int i = 0; n > 0; i++) {
		if (dp_sum[x] != -1) {
			sum += n / (i - dp_idx[x]) * (sum + x - dp_sum[x]);
			n %= (i - dp_idx[x]);
			while (n > 0) {
				
				sum += x;
				x = x * x % m;
				n--;
			}
			cout << sum;
			return 0;
		}
		sum += x;
		dp_sum[x] = sum;
		dp_idx[x] = i;
		x = x * x % m;
		n--;
	}
	cout << sum;
}