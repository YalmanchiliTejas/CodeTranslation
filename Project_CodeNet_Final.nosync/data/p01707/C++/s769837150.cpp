#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <complex>

using namespace std;

#define mod 1000000007

vector<long long int> factinv(2001);
vector<long long int> product_from_d(2001);

void setfactinv()
{
	vector<vector<long long int> > tmpv(30, vector<long long int>(2001));
	tmpv[0][0] = 1;
	for(int i = 1; i <= 2000; i++){
		tmpv[0][i] = (tmpv[0][i - 1] * i) % mod;
	}
	for(int i = 1; i < 30; i++){
		for(int j = 0; j <= 2000; j++){
			tmpv[i][j] = (tmpv[i - 1][j] * tmpv[i - 1][j]) % mod;
		}
	}
	for(int i = 0; i <= 2000; i++){
		long long int rest = mod - 2;
		long long int res = 1;
		for(int j = 29; j >= 0; j--){
			if(rest >= (1 << j)){
				rest -= (1 << j);
				res *= tmpv[j][i];
				res %= mod;
			}
		}
		factinv[i] = res;
	}
}

void setproduct(long long int d)
{
	product_from_d[0] = 1;
	for(int j = 1; j <= 2000; j++){
		product_from_d[j] = (product_from_d[j - 1] * ((d - j + 1) % mod)) % mod;
		// cout << j << " " << product_from_d[j] << endl;
	}
}

long long int comb(int i)
{
	// cout << product_from_d[d][i] << endl;
	return (product_from_d[i] * factinv[i]) % mod;
}

long long int dp[2001][2001] = {};

int main()
{
	long long int n, d, x;
	setfactinv();
	while(1){
		cin >> n >> d >> x;
		if(n == 0) break;
		setproduct(d);
		// dp[i][j] : i日かけてj枚のクッキーを食べる
		for(int i = 0; i < 2001; i++){
			for(int j = 0; j < 2001; j++){
				dp[i][j] = 0;
			}
		}
		for(int i = 1; i < x; i++){
			dp[1][i] = 1;
		}
		for(int i = 2; i <= min(d, n); i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod;
				if(j >= x) dp[i][j] -= dp[i - 1][j - x] - mod;
				dp[i][j] %= mod;
				// cout << i << " " << j << " " << dp[i][j] << endl;
			}
		}
		long long int ans = 0;
		for(int i = 1; i <= min(d, n); i++){
			ans += (comb(i) * dp[i][n]) % mod;
			ans %= mod;
			// cout << i << " " << ans << endl;
		}
		cout << ans << endl;
	}
	return 0;
}
