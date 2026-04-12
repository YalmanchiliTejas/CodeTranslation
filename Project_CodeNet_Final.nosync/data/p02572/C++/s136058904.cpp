#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <functional>
#include <numeric>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
	int N;
	cin >> N;
	vector<ll> vec(N);
	for (int i = 0; i < N; i++) cin >> vec.at(i);
	ll ans = 0;
	ll mod = (ll)1e9 + 7;
	ll tmp = 0;
	for (int i = 1; i < N; i++) {
		tmp += vec.at(i-1);
		tmp %= mod;
		ans += vec.at(i) * tmp;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}