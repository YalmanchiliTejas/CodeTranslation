#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	ll ans = 0;
	if(C*2>A+B) ans = A*X+B*Y;
	else {
		if(X<Y){
			ans += C*2*X;
			ans += (C*2<B)? C*2*(Y-X):B*(Y-X);
		}else if(X==Y){
			ans = C*2*X;
		}else{
			ans += C*2*Y;
			ans += (C*2<A)? C*2*(X-Y):A*(X-Y);
		}
	}
	
	cout << ans << endl;
}