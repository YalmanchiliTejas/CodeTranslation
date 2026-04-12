#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;
unsigned long long a[1000005], cnt, sum;
int n;
int main()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		sum = sum + a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		sum = sum - a[i];
		cnt = (cnt + (sum % mod * a[i]) % mod) % mod; 
	}
    cout << cnt << endl;
	return 0;
} 
/* 1 2 3 4 5
2 3 4 5 6 8 10 12 15 20
*/