#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C,X,Y;
	int value;
	cin >> A >> B >> C >> X >> Y;
	if(A+B <= 2*C){
		value = A * X + B * Y;
	}
	else{
		int M = min(X,Y);
		int D = max(X,Y) - M;
		int E;
		if(X > Y) E = A;
		else E = B;
		value = 2 * M * C + min(2*C,E) * D;
	}
	cout << value << endl;
	return 0;
}