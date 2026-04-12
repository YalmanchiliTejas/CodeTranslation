#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std;
typedef long long LL;
const int N = 2e5+10 , mod = 1e9+7;
inline int read()
{
	register int x = 0 , f = 0; register char c = getchar();
	while(c < '0' || c > '9') f |= c == '-' , c = getchar();
	while(c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0' , c = getchar();
	return f ? -x : x;
}
int n , m;
char s[N];
int sum[N] , f[N];
int main()
{
	n = read(); m = read(); scanf("%s" , s+1);
	int i , mx , ans = 0;
	for(i = 1 ; i <= m ; ++i) if(s[i] != s[1]) break;
	mx = i - 1;
	if(mx == m)
	{
		sum[0] = f[0] = ans = 1;
		for(int i = 1 ; i <= n ; ++i)
		{
			if(i >= 2) f[i] = sum[i-2];
			sum[i] = (sum[i-1] + f[i]) % mod;
		}
		for(int i = 0 ; n - i >= 2 ; ++i) (ans += (LL)f[i] * (n - i) % mod) %= mod;
		cout << ans << '\n'; return 0;
	}
	if(n & 1) return puts("0") , 0;
	if(mx % 2 == 0) mx++;
	for(int tmp = 0 ; i <= m ; ++i)
	{
		if(s[i] == s[1]) tmp++;
		else
		{
			if(tmp & 1) mx = min(mx , tmp);
			tmp = 0;
		}
	}
	mx = (mx + 1) >> 1; n >>= 1; f[0] = sum[0] = 1;
	for(int i = 1 ; i <= n ; ++i)
	{
		f[i] = (sum[i-1] - (i - mx - 1 >= 0 ? sum[i - mx - 1] : 0) + mod) % mod;
		sum[i] = (sum[i-1] + f[i]) % mod;
	}
	for(int i = 0 ; i <= n ; ++i) if(n - i <= mx) (ans += (LL)f[i] * (n - i) % mod * 2 % mod) %= mod;
	cout << ans << '\n'; return 0;
}