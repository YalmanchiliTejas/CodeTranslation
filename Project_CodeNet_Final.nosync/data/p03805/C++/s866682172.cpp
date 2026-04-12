#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
bool path[10][10];
int main() {
	int n, m;
	cin >> n >> m;
	
	rep(i,m) {
			int a, b; cin >> a >> b;
			path[a-1][b-1] = true;
			path[b-1][a-1] = true;
	}
	vector<int> num(n-1);
	rep(i,n-1) num[i] = i+1;

	int ans = 0;
	do
	{
		int now = 0;
		bool ok = true;
		rep(i,n-1) {
			if (!path[now][num[i]]) ok = false;
			now = num[i]; 
		}
		if (ok) ans++;
	} while (next_permutation(num.begin(),num.end()));
	

	cout << ans << endl;
	return 0;
}