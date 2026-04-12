#include <queue>
#include <cstdio>
#include <iostream>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <stack>
using namespace std;
typedef long long int ll;

#define EPS (1e-9)
#define INF (1e9)
#define PI (acos(-1))
#define REP(i,n) for(int i=0;i<n;i++)

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll beki(ll a, ll b) {
	ll tmp = 1;
	REP(i, b) tmp *= a;
	return tmp;
}

int N;
int A[100010];
vector<int> dp;

int main() {
	cin >> N;
	REP(i, N) {
		int tmp;
		cin >> tmp;
		A[i] = -tmp;
	}
	REP(i, N) dp.push_back(INF);

	int ans = 0;

	//最長増加列
	REP(i, N) {
		auto it = upper_bound(dp.begin(), dp.end(), A[i]);
		int index = it - dp.begin();
		if (dp[index] == INF) ans++;
		dp[index] = A[i];
	}
	cout << ans << endl;
}