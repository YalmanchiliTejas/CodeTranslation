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

using namespace std;

#define mod 1000000007

int a, b, c, d;
long long int fact[1001];
long long int comb[1001][1001];
long long int powrev[1001];
vector<vector<long long int> > result(1001, vector<long long int>(1001, -1));
// result[i][j] : i人でグループを作る。最大のグループの人数がj人のとき、グループ分けが何通りあるか

long long int getpow(long long int n, long long int k)
{
	if(k == 0) return 1;
	long long int tmp = getpow(n, k / 2);
	if(k % 2 == 0) return (tmp * tmp) % mod;
	else return (((tmp * tmp) % mod) * n) % mod;
}
long long int solve(int n, int k)
{
	if(result[n][k] >= 0) return result[n][k];
	if(n == 0) return result[n][k] = 1;
	if(k < a) return result[n][k] = 0;
	result[n][k] = solve(n, k - 1);
	long long int tmp = 1;
	for(int i = 1; i <= c - 1; i++){
		if((i - 1) * k > n) return result[n][k];
		tmp *= (comb[n - (i - 1) * k][k] * powrev[i]) % mod;
		tmp %= mod;
	}
	for(int i = c; i <= d; i++){
		if(k * i > n) break;
		tmp *= (comb[n - (i - 1) * k][k] * powrev[i]) % mod;
		tmp %= mod;
		result[n][k] += (tmp * solve(n - k * i, k - 1)) % mod;
		result[n][k] %= mod;
	}
	// cout << n << " " << k << " " << result[n][k] << endl;
	return result[n][k];
}



int main()
{
	int n;
	cin >> n >> a >> b >> c >> d;
	comb[0][0] = 1;
	comb[1][0] = 1;
	comb[1][1] = 1;
	fact[0] = 1;
	fact[1] = 1;
	powrev[0] = 1;
	powrev[1] = 1;
	for(int i = 2; i <= n; i++){
		fact[i] = (fact[i - 1] * i) % mod;
		powrev[i] = getpow(i, mod - 2);
		for(int j = 0; j <= i; j++){
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		}
	}
	cout << solve(n, b) << endl;
}