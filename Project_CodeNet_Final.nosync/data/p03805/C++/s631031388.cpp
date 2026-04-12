#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;


int main() {
	ll numV, numE;
	cin >> numV >> numE;
	vector<set<ll>> adjacents;
	adjacents.resize(numV + 1);
	for (ll i = 0; i < numE; i++) {
		ll a, b;
		cin >> a >> b;
		adjacents[a].insert(b);
		adjacents[b].insert(a);
	}
	vector<ll> v;
	for (ll i = 2; i <= numV; i++) {
		v.push_back(i);
	}
	ll ans = 0;
	do {
		bool success = true;
		vector<ll> order;
		order.push_back(1);
		for (ll i = 0; i < v.size(); i++) {
			order.push_back(v[i]);
		}
		for (ll i = 0; i < v.size(); i++) {
			if (adjacents[order[i]].find(order[i + 1]) == adjacents[order[i]].end()) {
				success = false;
				break;
			}
		}
		if (success) {
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << endl;
}
