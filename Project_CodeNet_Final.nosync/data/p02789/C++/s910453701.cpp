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
	int n, m;
	cin >> n >> m;

	if (n == m)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}