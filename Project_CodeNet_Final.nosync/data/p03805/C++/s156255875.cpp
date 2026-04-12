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
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> path(n, vector<bool>(n, false));

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		path[a - 1][b - 1] = true;
		path[b - 1][a - 1] = true;
	}

	vi p = {};
	rep(i, n)p.push_back(i);
	int ans = 0;

	do{
		bool can = true;

		rep(i, p.size()-1) {
			if (path[p[i]][p[i + 1]] == false)can = false;
		}

		if (can)ans++;
	
	} while (next_permutation(p.begin()+1,p.end()));

	cout << ans << endl;

}