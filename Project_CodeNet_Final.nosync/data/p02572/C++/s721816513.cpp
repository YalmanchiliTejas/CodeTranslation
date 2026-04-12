#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	vector<long long> av(n);
	long long suma = 0;
	for (auto& a : av) {
		cin >> a;
		suma += a;
	}

	long long ret = 0;
	for (long long i = 0; i < n - 1; ++i) {
		suma -= av[i];
		long long tempa = suma % 1000000007;
		ret += av[i] * tempa;
		ret %= 1000000007;
	}

	cout << ret << endl;

	return 0;
}