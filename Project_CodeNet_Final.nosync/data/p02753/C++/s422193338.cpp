#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

#include <set>
#include <map>
#include <iomanip>

using namespace std;

#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define rrep(i, n) for(long long i = (long long)(n - 1); i >= 0; i--)
#define all(x) (x).begin(),(x).end()

using ll = long long;

int main()
{
	string s;
	cin >> s;

	bool a = false, b = false;
	for (auto x : s)
	{
		if (x == 'A') a = true;
		else b = true;
	}

	if (a && b)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}


	return 0;
}