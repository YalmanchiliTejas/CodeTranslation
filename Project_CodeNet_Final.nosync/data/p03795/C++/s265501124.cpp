#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

int main()
{
	int ans,n,r;
	cin >> n;
	r = (n / 15);
	ans = n * 800 - r * 200;
	cout << ans << endl;

	return 0;
}