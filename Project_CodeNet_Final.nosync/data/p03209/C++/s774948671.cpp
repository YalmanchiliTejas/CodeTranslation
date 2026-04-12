#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
long long f[maxn], g[maxn];
int main(){
	f[0] = 1;
	g[0] = 1;
	for(int i = 1; i < maxn; i++) f[i] = 2 * f[i - 1] + 1;
	for(int i = 1; i < maxn; i++) g[i] = 2 * g[i - 1] + 3;
	int n; long long x; cin >> n >> x;
	long long ans = 0;
	while(n > 0 && x){
		if(x == 1){
			n = 0;
			x = 0;
		} else if(abs(x - g[n]) <= 1){
			ans += f[n];
			n = 0;
			x = 0;
		} else {
			x--;
			if(x < g[n - 1]){
				n--;
			} else if(x == g[n - 1]){
				ans += f[n - 1];
				n = 0;
				x = 0;
			} else {
				ans += f[n - 1];
				ans += 1;
				x -= g[n - 1];
				x--;
				n--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

