#include <iostream>
using namespace std;
#define M 1000000007
int main()
{
	long long a[200000], i,n, j, s=0, su=0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		s=(s+a[i])%M;
	}
	for (i = 0; i < n; i++)
	{
		s -= a[i];
		s+=M;
		s%=M;
		su += (a[i] * s)%M;
		su %= M;
	}
	cout << su;
}