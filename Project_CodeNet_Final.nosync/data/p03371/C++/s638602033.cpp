#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	int a,b,c,x,y;
	cin >>a>>b>>c>>x>>y;
	int ans = INF*2;
	int up = max(x,y);
	rep(i, up+1) {
		ans = min(ans, 2*c*i+a*max(0,x-i)+b*max(0,y-i));
	}
	cout << ans << endl;
	return 0;
}