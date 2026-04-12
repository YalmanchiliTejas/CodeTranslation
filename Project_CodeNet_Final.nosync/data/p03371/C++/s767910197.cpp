// C - Half and Half
#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	int ans;
	if(A+B > C*2){
		int min_n = min(X, Y);
		ans = C*2 * min_n;
		int rest_n = abs(X - Y);
		if(X > Y){//rest X -> A
			if(A > C*2) ans += C*2 * rest_n;
			else ans += A * rest_n;
		}
		else if(X < Y){//rest Y -> B
			if(B > C*2) ans += C*2 * rest_n;
			else ans += B * rest_n;
		}
	}
	else ans = A*X + B*Y;
	cout<< ans <<endl;
}