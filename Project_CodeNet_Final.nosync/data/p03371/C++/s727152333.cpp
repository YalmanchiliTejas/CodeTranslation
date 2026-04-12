#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int a,b,c,x,y;
	cin >>a>>b>>c>>x>>y;
	int upper = 2 * max(x, y);
	int ans = INF;
	for (int i = 0; i <= upper; i += 2) 
	{
		int now = i*c + max(x-i/2, 0)*a + max(y-i/2, 0)*b;
		
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}