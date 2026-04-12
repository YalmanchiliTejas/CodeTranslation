#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<functional>
#include<set>
using namespace std;
#define int long long
typedef pair<int, int>P;

signed main() {
	int n, k; cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) {//b
		int a = (n / i)*max(0ll,i-k);
		int mod = n%i;//0~mod
		if(mod)ans += max(0ll,mod - k+1 );
		
		ans += a;
	}
	if (k == 0)cout << n*n << endl;
	else cout << ans << endl;
}