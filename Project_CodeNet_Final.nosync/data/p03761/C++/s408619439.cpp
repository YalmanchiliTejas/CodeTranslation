#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <math.h>
#include <cmath>
#include <set>   
#include <bitset>
//#include <boost/math/common_factor_rt.hpp>

#define ll long long
int L = 1000000007;
using namespace std;
string s[60] = {};
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	string ans;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int small = 100;

		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < s[i].length(); j++)
			{
				if (s[i][j] == c)cnt++;
				
			}
			small = min(small, cnt);
		}
		for (int i = 0; i < small; i++)
		{
			ans += c;
		}
		
	}
	cout << ans << endl;
	
	return 0;
}

int dsum(ll a) {
	int ans = 0;
	while (a != 0) {
		ans += a % 10;
		a /= 10;
	}
	return ans;
}
