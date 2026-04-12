#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100000;

int main() {
	int n;
	cin >> n;
	vector<ll> v(n + 1, -1);
	v[n] = INFL;
	rep(i, n) {
		ll a;
		cin >> a;
		int j = lower_bound(v.begin(), v.end(), a) - v.begin() - 1;
		v[j] = a;
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(v[i] == -1) break;
		else ans++;
	}
	cout << ans << endl;
}
