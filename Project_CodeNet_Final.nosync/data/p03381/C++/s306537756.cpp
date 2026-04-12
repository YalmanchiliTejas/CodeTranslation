#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
//const int mod = 1000000007;
const int INF = 1 << 28;
const double EPS = 1e-10;
//cout << fixed << std::setprecision(9) << flush;
//memset(a, 0, sizeof(a));
//--------------------------

int n;
vector<int> x,y;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) {
		int t;
		cin >> t;
		x.push_back(t);
		y.push_back(t);
	}

	sort(y.begin(), y.end());
	for (int i = 0;i < n;i++) {
		int k = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
		if (k < n / 2) {
			cout << y[n / 2] << endl;
		}
		else {
			cout << y[n / 2 - 1] << endl;
		}
	}

	return 0;
}
