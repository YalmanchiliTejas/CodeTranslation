#include <bits/stdc++.h>
#define REP(a, b) for(int a = 0; a < b; a++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define mp make_pair
#define f first
#define s second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;

const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const int MAXN = 3e3 + 100;

ll DP[MAXN][MAXN][2];
ll n, A[MAXN];

ll rek(ll x, ll y, int pos) {
	if (x > y) return 0;
	ll &ret = DP[x][y][pos];
	if (ret != -1) return ret;
	if (pos == 0) ret = max(rek(x + 1, y, 1) + A[x], rek(x, y - 1, 1) + A[y]);
	else ret = min(rek(x + 1, y, 0), rek(x, y - 1, 0));
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	ll sum = 0;
	REP(i, n) {
		cin >> A[i];
		sum += A[i];
	}
	memset(DP, -1, sizeof DP);
	cout << 2 * rek(0, n - 1, 0) - sum << '\n';
}