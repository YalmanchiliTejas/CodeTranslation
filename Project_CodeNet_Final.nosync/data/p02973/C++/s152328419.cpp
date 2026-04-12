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
#define mod 10000000
#define int long long
#define double long double
#define INF LLONG_MAX/10
#define P pair<int,int>
#define prique priority_queue
using namespace std;
int n, a[100010];
multiset<int> st;
signed main() {
	cin >> n;
	rep(i, n)cin >> a[i];
	rep(i, n) {
		auto ite = st.lower_bound(a[i]);
		if (ite == st.begin())st.insert(a[i]);
		else {
			ite--;
			st.erase(ite);
			st.insert(a[i]);
		}
	}
	cout << st.size() << endl;
	return 0;
}