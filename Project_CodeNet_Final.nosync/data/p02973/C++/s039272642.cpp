#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<ll, ll> P;

#define rep(a,n) for(int a = 0;a < n;a++)

const ll LARGE = (ll)1e10;

int main(void)
{
	int n;
	cin >> n;
	vector<ll> as(n, 0);
	rep(i, n) {
		cin >> as[i];
		as[i] = -as[i];
	}
	set<pair<ll, ll>> s;
	s.insert(make_pair(as[0], 0));
	for (int i = 1; i < n; i++) {
		auto p = s.upper_bound(make_pair(as[i], LARGE));
		if (p == s.end()) {
			s.insert(make_pair(as[i], s.size()));
		}
		else {
			auto id = p->second;
			s.erase(p);
			s.insert(make_pair(as[i], id));
		}
	}
	cout << s.size() << endl;
	return 0;
}