#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<functional>
#include<iso646.h>
#include<bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const double INF = 1e16;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

ll const MAX_N = 1e5 + 10;
bool done[MAX_N];

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}


int main() {
	ll i, j;
	ll N;
	cin >> N;
	vll A(N);
	for (auto& e : A)cin >> e;
	multiset<ll> E ;
	for (auto a : A) {
		auto it = E.lower_bound(a);
		//it--;
		if (it == E.begin()) {
			E.insert(a);
		}
		else {
			it--;
			E.erase(it);
			E.insert(a);
		}
	}
		cout << E.size() << endl;

	return 0;
}
