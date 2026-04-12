#include <bits/stdc++.h>
using namespace std;

int y[10005];

int main(){
while(1){	
	
	int n, a, b, c, x;
	cin >> n >> a >> b >> c >> x;
	if(n == 0 and a == 0 and c == 0 and x == 0) break;
	for(int i=0; i<n; i++) cin >> y[i];
	int ans = 0;
	
	int i = 0;
	while(1){
		if(x == y[i]) i += 1;
		x = (a * x + b) % c;
		if(i == n) break;
		ans += 1;
		if(ans == 10001) break;
	}
	
	if(ans > 10000) cout << -1 << endl;
	else cout << ans << endl;

	
}//end
	return 0;
}
