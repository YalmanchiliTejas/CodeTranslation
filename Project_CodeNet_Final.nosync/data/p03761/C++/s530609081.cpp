#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
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
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}





int main() {
	ll n;
	cin >> n;
	string an = "";
	vector<string> S(n);
	rep(i, n) {
		cin >> S.at(i);
	}
	rep(j, 26) {
		char k = 'a' + j;
		ll M = 99;
		rep(i, n) {
			ll co = 0;
			rep(h, S.at(i).size()) {
				
				if (S.at(i).at(h) == k) {
					co++;
				}
			}
			M = min(M, co);
		}

		rep(i, M) {
			an += k;
		}
	}
	cout << an << endl;

}
