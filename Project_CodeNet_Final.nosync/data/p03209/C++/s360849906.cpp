#include <iostream>
#include <cmath>
using namespace std;

long Npate(int N, long X) {
	long lnm1 = pow(2,N+1)-3;
	long pnm1 = pow(2,N)-1;
	if (N==0) {
		if (X>=1) return 1;
		else return 0;
	}
	if (X<=1) return 0;
	else if (X>=1+lnm1+1) {
		return pnm1+1+Npate(N-1, X-(1+lnm1+1));
	} else {
		return Npate(N-1, X-1);
	}
}

int main() {
	long N,X;
	cin >> N >> X;

	cout << Npate(N,X) << endl;

	return 0;
}
