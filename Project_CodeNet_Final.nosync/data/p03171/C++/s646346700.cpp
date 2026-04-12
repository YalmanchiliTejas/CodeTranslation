#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

const int N = 3000 + 5;

int n;
ll arr[N];

ll memo[N][N][2];

ll solve(int i, int j, bool turn)
{
	if (i > j)
		return 0;

	ll &ret = memo[i][j][turn];

	if (~ret)
		return ret;

	if (!turn)
	{
		ret = -1e16;
		ret = max(ret, arr[i] + solve(i + 1, j, !turn));
		ret = max(ret, arr[j] + solve(i, j - 1, !turn));
	}
	else
	{
		ret = 1e16;
		ret = min(ret, -arr[i] + solve(i + 1, j, !turn));
		ret = min(ret, -arr[j] + solve(i, j - 1, !turn));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 0, n)
		cin >> arr[i];

	reset(memo, -1);
	cout << solve(0, n - 1, 0) << endl;

	return 0;
}
