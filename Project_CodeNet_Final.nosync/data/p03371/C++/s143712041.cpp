#include <bits/stdc++.h>
using namespace std;
int main () {
	int A,B,C,X,Y;
	long long money = 0;
	cin >> A>>B>>C>>X>>Y;
	int minKind = min(X,Y);
	money += minKind * min(A+B,2*C);
	if(X>Y){
		int left = X - Y;
		if(A > 2 * C){
			money += 2 * C * left;
		}else{
			money += A * left;
		}
	}else{
		int left = Y - X;
		if(B > 2 * C){
			money += 2 * C * left;
		}else{
			money += B * left;
		}
	}
	cout << money << endl;
}