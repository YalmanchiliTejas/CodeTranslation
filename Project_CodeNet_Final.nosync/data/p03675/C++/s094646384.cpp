#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>

#define	MOD 1000000007;
#define PI 3.14159265358979323846;
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	int n;
	cin >> n;

	ll a[200000];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (n % 2 == 0)
	{
		for (int i = n - 1; i >= 0; i -= 2) {
			printf("%lld ", a[i]);
		}
		for (int i = 0; i < n; i += 2) {
			printf("%lld ", a[i]);
		}
	}
	else {
		for (int i = n - 1; i >= 0; i -= 2) {
			printf("%lld ", a[i]);
		}
		for (int i = 1; i < n; i += 2) {
			printf("%lld ", a[i]);
		}
	}
	printf("\n");
	return 0;
}