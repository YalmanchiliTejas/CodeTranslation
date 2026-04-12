#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	multiset<int> cc;

	rep(i, n) {
		auto k = cc.lower_bound(a[i]);
		if (k != cc.begin()) {
			k--; cc.erase(k);
		}
		cc.insert(a[i]);
	}

	cout << cc.size() << endl;
}