#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define dunk(a) cout << (a) << "\n"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	deque<int> res;
	res.push_back(a[0]);
	rrep(i, n) {
		int it = lower_bound(all(res), a[i]) - res.begin();
		if (!it) res.push_front(a[i]);
		else res[it - 1] = a[i];
	}
	dunk(res.size());
	return 0;

}