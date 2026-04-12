#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define INF 21000000000

signed main(){
		int a,b,c,n,m;
		cin >> a >> b >> c >> n >> m;
		int ans;
		if(a + b > c * 2){
				if(n > m) ans = c * m * 2 + a * (n - m);
				else ans = c * n * 2 + b * (m - n);
		}else{
				ans = a * n + b * m;
		}
		if(n > m){
				if(ans > c * n * 2) ans = c * n * 2;
		}else{
				if(ans > c * m * 2) ans = c * m * 2;
		}
		cout << ans << endl;
}

