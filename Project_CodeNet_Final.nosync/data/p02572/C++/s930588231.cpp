#include <iostream>
#define ll long long
using namespace std;

const ll MD = 1e9 + 7, I2 = 5e8 + 4;

int n;
ll res1, res2;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll x; cin >> x; res2 += MD - x * x % MD;
		res2 %= MD;
		res1 += x;
		res1 %= MD;
	}
	cout << (res1 * res1 + res2) % MD * I2 % MD << "\n";
	return 0;
}