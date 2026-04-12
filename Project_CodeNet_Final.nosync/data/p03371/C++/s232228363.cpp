#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SORT(i) sort((i).begin(),(i).end())
constexpr int INF = 2000000000;
constexpr int mod = 1000000007;

int main() {
	int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
	c *= 2;
	int ans = min(a+b,c)*min(x,y);
	if (x < y) {
		int num = y - x;
		ans += min(b, c) * num;
	}
	else if (x > y) {
		int num = x - y;
		ans += min(a, c) * num;
	}
	cout << ans << "\n";

	return 0;
}