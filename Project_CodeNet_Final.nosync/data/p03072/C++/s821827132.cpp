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

#define int64 long long
#define uint64 unsigned long long
#define PI 3.1415926535897932384626433832795
#define coutfix(i) cout << fixed << setprecision(i)
using namespace std;

int main()
{
	int64 nn, ans = 1;
	cin >> nn;
	vector<int64> hh(nn);
	for(int64 ii = 0;ii < nn;ii++)
	{
		cin >> hh[ii];
	}
	for(int64 ii = 1;ii < nn;ii++)
	{
		if(hh[ii - 1] <= hh[ii])
		{
			ans++;
		}
		else
		{
			hh[ii] = hh[ii - 1];
		}
	}
	cout << ans << endl;
}
