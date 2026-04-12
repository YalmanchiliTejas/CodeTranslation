// Half and Half

#include <iostream>

using namespace std;

int main(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (A+B >= 2*C){
		if (X <= Y)
			cout << 2*C*X + min(B, 2*C)*(Y-X) << endl;
		else
			cout << 2*C*Y + min(A, 2*A)*(X-Y) << endl;
	}else{
		cout << A*X + B*Y << endl;
	}

	return 0;
}