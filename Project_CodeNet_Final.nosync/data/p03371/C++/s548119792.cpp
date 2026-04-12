// C - Half and Half
#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
	int ans;
	if(A+B > C*2){
		int min_n = min(X, Y);
		ans = C*min_n*2;
		int rest_n = max(X, Y) - min_n;
		if(X > Y){//rest X -> A
			if(A > C*2) ans += C * rest_n * 2;
			else ans += A * rest_n;
		}
		else if(X < Y){//rest Y -> B
			if(B > C*2) ans += C * rest_n * 2;
			else ans += B * rest_n;
		}
	}
	else ans = A*X + B*Y;
	cout<< ans <<endl;
}