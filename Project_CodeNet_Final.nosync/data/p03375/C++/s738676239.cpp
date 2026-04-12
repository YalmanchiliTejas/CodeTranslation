#include<bits/stdc++.h> 
using namespace std;
int n;
long long ans , s[3100][3100] , c[3100][3100] , p[3100 * 3100];
long long t , v = -1 , vv , mod;
inline long long exp( long long a , long long b , long long mod )
{
	long long ans = 1 , t = a;
	while(b)
	{
		if(b & 1)
		{
			ans *= t; ans %= mod;
		}
		b >>= 1;
		t *= t; t %= mod;
	}
	return ans;
}
void init()
{
	p[0] = 1; c[0][0] = s[0][0] = 1;
	for(int i = 1 ; i <= n * n ; i++ ) p[i] = p[i - 1] * 2 % mod;
	for(int i = 1 ; i <= n + 1 ; i++ )
	{
		s[i][0] = 0; c[i][0] = 1;
		for(int j = 1 ; j <= i ; j++ )
		{
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % mod;
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	return ;
}
int main()
{
	scanf("%d%lld" , &n , &mod);
	init();
	for(int i = 0 ; i <= n ; i++ )
	{
		v *= -1;
		vv = exp(2 , exp(2 , n - i , mod - 1) , mod) * c[n][i] % mod;
		t = 0;
		for(int j = 0 ; j <= i ; j++ )
		{
			t += s[i + 1][j + 1] * p[(n - i) * j] % mod; t %= mod;
		}
		ans += t * v * vv % mod; ans = (ans % mod + mod) % mod;
	}
	printf("%lld" , (ans % mod + mod) % mod);
	return 0;
}