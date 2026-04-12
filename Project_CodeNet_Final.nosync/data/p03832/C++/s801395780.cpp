#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a;
int b;
int c;
int d;

typedef long long ll;

ll nCr[1001][1001];

ll fact[1001];

ll inv_f[1001];

ll MOD = 1e9 + 7;


ll dp[1010][1010];

ll inv_mod( ll a, ll m = MOD )
{
  ll b, x, u, q, abs_m, tmp; 

  abs_m = ( m < 0 ) ? -m : m;
  b = m; x = 1; u = 0; 
  while ( b > 0 ) {
    q = a / b; 
    tmp = u; u = x - q * u; x = tmp;
    tmp = b; b = a - q * b; a = tmp;
  }

  return ( x < 0 ) ? abs_m + x : x;
}



int main()
{
	fact[0] = 1;
	inv_f[0] = 1;

	for(int i = 1;i <= 1000;i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;

		inv_f[i] = inv_mod(fact[i]) % MOD;
	}


	for(int i = 0;i <= 1000;i++)
	{
		for(int j = 0;j <= 1000;j++)
		{
			if(j == 0 || j >= i)
			{
				nCr[i][j] = 1;
			}
			else
			{
				nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
			}
		}
	}

	cin >> n >> a >> b >> c >> d;

	dp[0][a - 1] = 1;

	for(int i = 0;i <= n;i++)
	{
		for(int j = a;j <= b;j++)
		{
			dp[i][j] = 0;
			ll comb = 1;
			for(int k = 0;k <= i / j;k++)
			{
				if(k > 0)
					comb = (comb * nCr[n - (i - j * (k))][j]) % MOD;
				//cout << "comb " << j << "*" << k << "=" << comb << endl;
				if(k == 0 || (c <= k && k <= d))
				{
					dp[i][j] = (dp[i][j] + dp[i - j * k][j - 1] * comb % MOD * inv_f[k]) % MOD;
				}
			}

			//cout << i << " " << j << "=" << dp[i][j] << endl;
		}
	}

	cout << dp[n][b] % MOD << endl;
	return 0;
}
		