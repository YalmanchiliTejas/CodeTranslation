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

int main(void)
{
	int n;
	cin >> n;
	vector<ll> as(n, 0);
	rep(i, n) {
		cin >> as[i];
	}
	vector<ll> ans;
	for (auto e : as) {
		auto it = upper_bound(ans.begin(), ans.end(), e, std::greater<ll>());
		if (it == ans.end()) ans.push_back(e);
		else *it = e;
	}
	cout << ans.size() << endl;
	return 0;
}