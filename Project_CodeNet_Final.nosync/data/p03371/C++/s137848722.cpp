#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);++i)
#define per(i,l,r) for(int i=(r)-1;i>=(l);--i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
int x, y, a, b, c;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
  cin >> a >> b >> c >> x >> y;
  int ans = INT_MAX;
  rep(xy, 0, max(x, y) + 1) {
  	int rx = max(0, x - xy);
  	int ry = max(0, y - xy);
		ans = min(ans, rx * a + ry * b + xy * c * 2);
	}
	cout << ans;
	return 0;
}