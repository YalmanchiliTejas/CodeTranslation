#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n,a,b;
	cin >> n >> a >> b;
	if(n <= a) cout << 1 << endl;
	else if(a == b) cout << -1 << endl;
	else{
		int ans = (n - b - 1) / (a - b);
		if(ans < 0) cout << -1 << endl;
		else cout << ans * 2 + 1 << endl;
	}
	return 0;
}