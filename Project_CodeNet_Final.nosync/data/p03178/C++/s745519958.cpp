 /*DavitMarg*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <stack>
#include <cassert>
#include <iterator>
#include <ctype.h>>
#include <fstream>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair
#define PB push_back
#define all(v) v.begin(),v.end()
using namespace std;
string s;
int n,d,mn,dp[10004][102];
int main()
{
	cin >> s >> d;
	n = s.length();
	for (int i = 0; i < n; i++)
	{
		if(i)
			for (int k = 0; k <= 9; k++)
				for (int j = 0; j < d; j++)
				{
					dp[i][(j + k) % d] += dp[i-1][j];
					dp[i][(j + k) % d] %= mod;
				}
		for (int k = 0; k < s[i] - '0'; k++)
		{
			dp[i][(mn + k) % d]++;
			dp[i][(mn + k) % d] %= mod;
		}
		mn = (mn + s[i] - '0') % d;
	}
	cout << (mod+dp[n - 1][0] + (mn == 0)-1)%mod << endl;
	return 0;
}

/*



*/