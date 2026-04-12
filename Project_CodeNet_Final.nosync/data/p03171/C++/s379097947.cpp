#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <string.h>
#include <iterator>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <limits.h>
#include <string>
#include <bitset>
#include <map>
#include <numeric>
#include<unordered_map>


#define endl cout<<"\n"
#define lli long long int
#define ld long double
#define M_PI (3.14159265358979323846264338327950288)
#define MOD (1000000007)

using namespace std;

//fast-exponentiation-lli
unsigned lli expo_fast(lli a, lli b) {
	a = a;
	lli result = 1;
	while (b) {
		//multiplyint(tos(result), a);
		if (b & 1)result = (result * a);
		b >>= 1;
		a = (a*a);
	}
	return (result);
}


void take_in(vector<lli> *arr) {
	for (int i = 0; i < arr->size(); i++)cin >> (*(arr))[i];
}


lli gcd(lli a, lli b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}

/* Iterative Function to calculate (x^y)%p in O(log y) */
unsigned lli power(lli x, unsigned lli y, lli p)
{
	lli res = 1;      // Initialize result 
	x = x % p;  // Update x if it is more than or equal to p 
	while (y > 0) {
		// If y is odd, multiply x with result 
		if (y & 1)res = (res*x) % p;
		// y must be even now 
		y = y >> 1;
		x = (x*x) % p;
	}
	return res;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n; cin >> n;
	vector<lli>arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	//int dp[3003][3003][2];
	vector<vector<vector<lli>>> dp(n + 1, vector<vector<lli>>(n + 1, vector<lli>(2)));
	for (int i = 1; i <= n; i++) {
		dp[i][i][0] =  arr[i];
		dp[i][i][1] = -1*arr[i];
	}
	for (int sz = 2; sz <= n; sz++) {
		for (int i = 1; i + sz - 1 <= n; i++) {
			int j = i + sz - 1;
			dp[i][j][0] = max(arr[j] + dp[i][j - 1][1], arr[i] + dp[i + 1][j][1]);
			dp[i][j][1] = min( dp[i][j - 1][0] - arr[j],  dp[i + 1][j][0] - arr[i]);
		}
	}
	cout << dp[1][n][0];
	//system("PAUSE");
}
