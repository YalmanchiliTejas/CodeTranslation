#include<cstdio>
#include<iostream>

using namespace std;
const int N = 200005;
const int mod = 1000000007;
typedef long long LL;
int a[N], sum = 0, n;
LL tot = 0;
int main()
{
 	cin >> n;
 	for(int i = 1; i <= n; i ++)
 	{
		cin >> a[i];
		tot += a[i];
 	}
 	for(int i = 1 ; i <= n; i ++)
 	{
 		tot -= a[i];
 		sum = (sum + int((tot % mod * a[i]) % mod)) % mod;
	}
	cout << sum;
	 return 0;
}