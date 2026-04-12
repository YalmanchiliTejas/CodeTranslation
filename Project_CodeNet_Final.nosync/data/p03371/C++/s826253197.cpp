// Score: /300

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	uint64_t A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	uint64_t a=0,b=0,c=0;
	uint64_t fee=0;

	c =min(X,Y)*2;
	if(X>Y){
		a = X-Y;
	}else{
		b = Y-X;
	}
	fee = a*A+b*B+c*C;

	a=X;
	b=Y;
	c=0;
	uint64_t n_fee = a*A+b*B+c*C;
	fee = fee > n_fee ? n_fee : fee;

	a=0;
	b=0;
	c =max(X,Y)*2;
	n_fee = a*A+b*B+c*C;
	fee = fee > n_fee ? n_fee : fee;

	cout << fee;
}
