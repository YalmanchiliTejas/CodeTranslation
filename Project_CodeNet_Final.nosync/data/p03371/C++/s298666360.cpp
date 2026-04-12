#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 1<<30;
	for (int i = 0; i <= max(2*x,2*y) ; i+=2)
	{
		int la = max(0, x - i / 2);
		int lb = max(0, y - i / 2);
		ans = min(ans, la * a + lb * b + i * c);
	}
	cout << ans << endl;

}