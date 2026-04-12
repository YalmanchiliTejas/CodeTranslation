#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>

#define PI 3.14159265358979323846
#define int64 long long
#define uint64 unsigned long long
#define coutfix(i) cout << fixed << setprecision(i)		//coutの浮動小数出力の桁数設定
using namespace std;

const int64 mod = 1000000007;

int main()
{
	int64 nn, ans = 0, sum = 0;
	cin >> nn;
	vector<int64> aa(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> aa[ii];
		sum += aa[ii];
		sum %= mod;
	}
	for(int64 ii = 0;ii < nn;ii++)
	{
		sum -= aa[ii];
		if(sum < 0)
		{
			sum += mod;
		}
		ans += (sum * aa[ii]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}