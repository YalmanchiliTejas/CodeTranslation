#include <bits/stdc++.h>
using namespace std;

#define log(x) cout << (x) << endl
using ll = long long;

int main() {

	ll A,B,C,x,y;
	cin>>A>>B>>C>>x>>y;

	if (C*2 > A+B) {
		log(A*x + B*y);
	}
	else {
		ll m = min(x,y) * 2, cst = 0;
		cst += C*m;

		if (x > y) {
			if (C*2 < A) cst += C * ((x-y) * 2);
			else cst += A * (x-y);
		}
		else if (y > x) {
			if (C*2 < B) cst += C * ((y-x) * 2);
			else cst += B * (y-x);
		}

		log(cst);
	}


	return 0;
}
