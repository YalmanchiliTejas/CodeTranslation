#include <sys/time.h>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using VP = pair<int, pair<int, int> > ;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

const int maxE = 300010;
int parent[maxE];
int parent_rank[maxE];


int main() {
	int n;
	cin >> n;
	ll a[n];
	rep(i, n) {
		cin >> a[i];
	}
	ll ans = 0;
	ll sum = 0;
	for(int i = n - 1; i >= 0; i--) {
		ans = (ans + sum * a[i]) % mod;
		sum = (sum + a[i]) % mod;
	}
	cout << ans << endl;

	return 0;
}
