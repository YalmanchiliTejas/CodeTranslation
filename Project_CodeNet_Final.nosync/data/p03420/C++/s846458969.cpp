#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, k, s;
int main()
{
	int i;
	cin >> n >> k;
	for (i = k + 1; i <= n; i++)
		s += n / i * (i - k) + max(0LL, (n % i > 0) * (n % i - max(0LL, k - 1)));
    cout << s << endl;
    return 0;
}