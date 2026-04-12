#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007
#define INF 1000000000000000
#define fi first
#define se second
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
struct edge { int to, cost; };
typedef pair<int, int> P;
int n;
int a[32];
int ma = 0;
int ans = 0;
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n) {
		if (ma <= a[i]) {
			ma = a[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}