#include<bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int ans = 1e9;
	if(a + b < 2*c){
		ans = a*x + b*y;
	}else{
		if(y > x){
			ans = min(ans, 2*c*x + (y-x)*b);
			ans = min(ans, 2*c*y);
		}else{
			ans = min(ans, 2*c*y + (x-y)*a);
			ans = min(ans, 2*c*x);
		}
	}

	cout << ans << endl;
}