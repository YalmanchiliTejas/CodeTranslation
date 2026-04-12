#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
const int N = 2e5 + 1000,mod = 1e9 + 7;
int n,m,k,isfirst = 1,len;
char s[N];
int A[N],B[N],ans;
signed main()
{
	k = 0x3f3f3f3f; n = read(); m = read(); scanf("%s",s + 1);
	for(int i = 1;i <= m;i ++)
	{
		if(s[i] != s[1]) {if(isfirst || len & 1) k = min(k,len / 2 + 1); isfirst = len = 0;}
		else len ++;
	}
	if(isfirst)
	{
		int x1 = 1,x2 = 0;
		for(int i = 1;i <= n;i ++)
		{
			x2 = (x1 + x2) % mod;
			x1 = (x2 - x1 + mod) % mod;
		}
		cout << (2ll * x1 + x2 ) % mod << "\n"; return 0;
	}
	if(n & 1) {puts("0"); return 0;}
	n /= 2; k = min(k,n);
	A[0] = B[0] = 1;
	for(int i = 1;i <= n;i ++)
	{
		A[i] = B[i - 1];
		if(i > k) A[i] = (A[i] - B[i - k - 1] + mod) % mod;
		B[i] = (B[i - 1] + A[i]) % mod; 
	}
	for(int i = 1;i <= k;i ++) ans = (ans + 2ll * i * A[n - i]) % mod;
	cout << ans << "\n";
	return 0;
}
