#include <iostream>
#include <math.h>

using namespace std;

long long int lnln(long long int N, long long int X) {
	if (N == 0) return 1;
	if (X == 1) return 0;
	else if (X <= pow(2,N+1) - 2) return lnln(N-1, X-1);
	else if (X == pow(2,N+1) - 1) return pow(2, N);
	else if (X >= pow(2,N+1) && X <= pow(2,N+2) - 4) return pow(2, N) + lnln(N-1, X-pow(2,N+1)+1);
	else if (X == pow(2,N+2) - 3) return pow(2,N+1) - 1;
	else return 0;
}

int main(void) {
	long long int N, X;
	cin >> N >> X;
	cout << lnln(N, X) << endl;

}
