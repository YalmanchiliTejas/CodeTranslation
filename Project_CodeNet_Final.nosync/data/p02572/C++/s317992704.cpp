#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 1000000007
using namespace std;
long long a[1100000];
long long b[1100000];
long long n,ans;
int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	for(int i=n - 1; i>=1; i--)
		b[i] = (b[i + 1] + a[i + 1]) % N;
	for(int i=1; i<=n - 1; i++)
		ans = ((ans % N) + (a[i] * b[i] % N)) % N;
	cout << ans << endl;
}