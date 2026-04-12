#include <bits/stdc++.h>
const int INF = ~0U>>1;
using namespace std;
int A, B, C;
int ans;
int X, Y;
int main(){
	cin >> A >> B >> C >> X >> Y;
	ans = INF;
	for(int i = 0; i <= max(X, Y); ++i) {
		ans = min(ans, 2 * C * i + max(X - i, 0) * A + max(Y - i, 0) * B);
	}
	cout << ans << endl;
return 0;
}
