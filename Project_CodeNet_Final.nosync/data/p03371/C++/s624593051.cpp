#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	int a, b, c, dc, x, y;
	ll ans = 0;
	cin >> a >> b >> c >> x >> y;
	dc = 2 * c;
	if(dc < a + b){
		int amari;
		if(x < y){
			ans = c * 2 * x;
			amari = y - x;
			if(dc < b){
				ans += dc * amari;
			}else{
				ans += b * amari;
			}
		}else{
			ans = c * 2 * y;
			amari = x - y;
			if(dc < a){
				ans += dc * amari;
			}else{
				ans += a * amari;
			}
		}
	}else{
		ans = a*x;
		ans += b*y;
	}
	cout << ans << endl;
	return 0;
}