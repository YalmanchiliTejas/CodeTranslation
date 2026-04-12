#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define	N	1000000007
 
int main()
{
	long long n, m, k,cost=0,t=1;
	cin >> n >> m >> k;
	for (long long i = 0; i < n; i++) cost = (cost + (1 + i) * i / 2 * m % N * m % N) % N;
	for (long long i = 0; i < m; i++) cost = (cost + (1 + i) * i / 2 * n % N * n % N) % N;
	for (long long i = 2; i <= n * m - 2; i++) cost = cost * i % N;
	for (long long i = 2; i <= k - 2; i++) t = t * i % N;
	for (long long i = 2; i <= (n * m - k); i++) t = t * i % N;
	for (long long x = N - 2; x > 0; t = t * t % N, x >>= 1)
		if (x & 1) cost = cost * t % N;
	cout << cost << endl;
 
	return 0;
}