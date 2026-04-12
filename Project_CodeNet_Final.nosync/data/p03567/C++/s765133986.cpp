#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	string S; cin >> S;
	for (int i = 0; i < S.length() - 1; ++i)
	{
		if (S[i] == 'A' && S[i + 1] == 'C')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}
