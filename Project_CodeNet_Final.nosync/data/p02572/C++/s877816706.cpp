#include <iostream>

const long long D = 1000000007;

int main()
{
	int N;
	long long q = 0;
	std::cin >> N;
	long long* A = new long long[N];
	for (int i=0; i<N; i++) std::cin >> A[i];
	long long res = 0;
	for (int i=0; i<N; i++) res += A[i];
	q += res / D; res %= D;
	res *= res;
	q += res / D; res %= D;
	//q = q*D;
	long long diagonal = 0;
	long long qd = 0;
	for (int i=0; i<N; i++) {
		diagonal += (A[i] * A[i]);
		qd += diagonal / D;
		diagonal %= D;
	}
	res -= diagonal;
	if (res < 0) { res += D; q++; } 
	// std::cout << q << std::endl;
	if ((q-qd)%2==0) std::cout << res/2 << std::endl;
	else std::cout << (D+res)/2 << std::endl;
	delete[] A;
	return 0;
}
