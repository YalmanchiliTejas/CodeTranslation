#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <numeric>
#include <regex>
#include <tuple>
#include <iomanip>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007 // 10^9 + 7
#define INF 1000000000 // 10^9
#define LLINF 1LL<<60
const double PI = 3.14159265358979323846;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];
	multiset<ll, greater<ll>> S;
	for (int i = 0; i < N; i++) {
		auto p = S.upper_bound(a[i]);
		if (p != S.end()) S.erase(p);
		S.insert(a[i]);
	}
	cout << S.size() << endl;

	return 0;
}