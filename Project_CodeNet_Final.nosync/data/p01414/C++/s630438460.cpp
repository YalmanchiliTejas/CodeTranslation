#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n;
int x[16], y[16];
bool used[1 << 16];
int ans[1 << 16];
char t[4][4];
int dfs(int s) {
	if (s == 0)return 0;
	if (used[s])return ans[s];
	used[s] = true;
	int mp[4][4] = {};
	rep(j, 16) {
		if (s&(1 << j)) {
			mp[j / 4][j % 4] = 1;
		}
	}
	int ret = mod;
	rep(i, 16) {
		for (int j = -3; j <= 3; j++) {
			for (int k = -3; k <= 3; k++) {

				int cs = s;
				char u = '?'; bool valid = true;
				for (int l1 = j; l1 < j + x[i]; l1++) {
					if (l1 < 0 || l1 >= 4)continue;
					for (int l2 = k; l2 < k + y[i]; l2++) {
						if (l2 < 0 || l2 >= 4)continue;
						if (!mp[l1][l2])continue;
						if (u == '?')u = t[l1][l2];
						else if (u != t[l1][l2])valid = false;
						int z = l1 * 4 + l2;
						cs ^= (1<<z);
					}
				}
				if (!valid)continue;
				if (s == cs)continue;
				ret = min(ret, dfs(cs));
			}
		}
	}
	return ans[s] = ret + 1;
}
int main() {
	cin >> n;
	rep(i, n) {
		cin >> x[i] >> y[i];
	}
	rep(i, 4) {
		rep(j, 4) {
			cin >> t[i][j];
		}
	}
	cout << dfs(65535) << endl;
	//cout << ans[65535] << endl;
	//stop
	return 0;
}

