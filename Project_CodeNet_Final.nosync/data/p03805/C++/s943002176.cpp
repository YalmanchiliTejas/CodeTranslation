#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define repf(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define repr(i,a,b) for(ll i=(ll)a;i<(ll)b;i--)
#define Fi fiest
#define Se second
const ll MAX = 1000000;
const char ENDL = '\n';

ll ans = 0;

void grf(vector<ll> visited, map<ll, set<ll>> branch, ll N) {
	if (visited.size() == N) {
		ans++;
		return;
	}

	for (auto x : branch[visited[visited.size() - 1]]) {
		bool flag = 1;
		for (auto y : visited) {
			if (x == y) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			vector<ll> visiteded = visited;
			visiteded.push_back(x);
			grf(visiteded, branch, N);
		}
	}
}

int main() {
	ll N, M, a, b;
	cin >> N >> M;
	map<ll, set<ll>> branch;
	rep(i, M) {
		cin >> a >> b;
		branch[a].insert(b);
		branch[b].insert(a);
	}
	vector<ll> visited = { 1 };
	grf(visited, branch, N);

	cout << ans << ENDL;
	return 0;
}