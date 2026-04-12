#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

const int N = 200005, P = 1e9 + 7;
int T, n;
long long a[N], x, y;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
	{
		x = (x + a[i]) % P;
		y = (y + a[i] * a[i]) % P;
	}
	x = (x * x - y + P) % P;
	if(x & 1) x += P;
	x >>= 1;
	cout << x << endl;
	return 0;
}
