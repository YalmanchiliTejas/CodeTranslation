#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ll ans = A*X + B*Y;
	rep(i,2*max(X,Y)+1) {
		int na = max(X-i/2, 0);
		int nb = max(Y-i/2, 0);
		ll comb = C*i + A*na + B*nb;
		ans = min(ans,comb);
	}
	cout << ans << endl;

	return 0;
}
