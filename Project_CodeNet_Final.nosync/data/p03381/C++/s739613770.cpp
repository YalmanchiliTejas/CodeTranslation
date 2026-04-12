#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<functional>
using namespace std;
#define int long long
#define inf 21145141919
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
struct edge { int to, cost; };
P x[200005];
int ans[200005];
signed main() {
	int n; cin >> n;
	rep(i, n) {
		int a; cin >> a; x[i] = P(a, i);
	}
	sort(x, x + n);

	rep(i, n) {
		int F = x[i].first, S = x[i].second;
		int mi;
		if (i < n / 2)mi = n / 2;
		else mi = n / 2 - 1;
		ans[S] = x[mi].first;
	}

	rep(i, n)cout << ans[i] << endl;
}