#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<map>
#include<cassert>
#include<vector>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const long long inf = 1145141919810000;
typedef pair<int, int> P;
int h[114514];
vector<int>Z;
vector<int>Pt;
signed main() {
	int n, x; cin >> n >> x;
	rep(i, 51) {
		Z.push_back((1ll << (i + 2) )- 3);
		Pt.push_back((1ll << (i + 1) )- 1);
	}
	int ans = 0;
	int as = Z[n];
	while (x) {
		x--;
		if (x >= Z[n - 1]) {
			ans += Pt[n - 1];
			x -= Z[n - 1];
			if (x >= 1) {
				x--;
				ans++;
			}
		}
		
		if (x >= Z[n - 1]) {
			ans += Pt[n - 1];
			x -= Z[n - 1];
			if (x >= 1)x--;
		}
		
		n--;
	}
	cout << ans << endl;
}