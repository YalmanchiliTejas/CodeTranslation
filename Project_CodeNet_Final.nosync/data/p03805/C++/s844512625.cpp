#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
int graph[10][10];
int main()
{
	int n, m;
	cin >> n >> m;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	vector<int> v(n);
	rep(i,n){
		v[i] = i;
	}
	int ans = 0;
	do
	{
		if (v[0] != 0)
			continue;
		bool find = true;
		rep(i, n - 1)
		{
			if(!graph[v[i]][v[i+1]])
				find = false;
		}
		ans += find ? 1 : 0;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	return 0;
}
