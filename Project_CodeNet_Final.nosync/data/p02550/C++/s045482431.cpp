
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
ll f(ll x, ll m) {
	return x % m;
}
ll dp[100005];
int main() {
	ll N, X, M;
	cin >> N >> X >> M;
	bool ch = true;
	ll A = X;
	ll an = 0;
	map<ll, ll> AP;
	AP[A] = 1;
	dp[1] = A;
	ll k = 1;
	ll j;
	while (k<=N) {
		k++;
		an += A;
		
		A = f(A * A, M);
		if (ch) {
			dp[k] = dp[k - 1] + A;
		}
		if (AP.count(A)&&ch) {
			
			j = k - AP[A];
			an += ((N - k) / j) * (dp[k] - dp[k - j]);
			k += ((N - k) / j) * j;
			ch = false;
		}
		AP[A] = k;
		
	}

	cout << an << endl;
}