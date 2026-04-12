#include <algorithm>
#include <bitset>
#include <cfloat>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod 1000000007
#define int long long
#define double long double
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a[51], b[51];
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	int ans = 0;
	while (true) {
		rep(i, n)b[i] = 0;
		rep(i, n) {
			if (a[i] >= n) {
				b[i] = a[i] / n;
				a[i] %= n;
			}
		}
		int sum = 0;
		rep(i, n)sum += b[i];
		if (!sum)break;
		rep(i, n) {
			a[i] += sum - b[i];
		}
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}