#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define INF 1000000007
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}

int n, ta[26][50], mu;
string s[50];

signed main() {
	cin >> n;
	rep(i, n) {
		cin >> s[i];
		rep(j, s[i].size()) {
			ta[s[i][j] - 'a'][i]++;
		}
	}
	vector<char> rin;
	rep(i, 26) {
		mu = 100;
		rep(j, n) {
			if (ta[i][j] < mu)mu = ta[i][j];
		}
		while (mu > 0) {
			rin.push_back(i + 'a');
			mu--;
		}
	}
	rep(i, rin.size())cout << rin[i];
	cout << endl;
	ggr
}