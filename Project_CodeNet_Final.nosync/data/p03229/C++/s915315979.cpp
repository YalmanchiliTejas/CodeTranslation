
#include <iostream>
#include <numeric>
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}

int main() {
	ll N,an=0;
	cin >> N;
	vector<ll> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
		an += vec.at(i);
	}
	an *= 2;
	sort(vec.begin(), vec.end());
	if (N % 2 == 0) {
		rep(i, N / 2) {
			an -= 4 * vec.at(i);
		}
		an += (vec.at(N / 2 - 1) - vec.at(N / 2));
	}
	else if(abs(vec.at(N/2-1)-vec.at(N/2))< abs(vec.at(N / 2 + 1) - vec.at(N / 2))) {
		rep(i, N / 2+1) {
			an -= 4 * vec.at(i);
		}
		an += (vec.at(N / 2 - 1) + vec.at(N / 2));

	}
	else {
		rep(i, N / 2 ) {
			an -= 4 * vec.at(i);
		}
		an-= (vec.at(N / 2 + 1) + vec.at(N / 2));
	}



	cout << an << endl;
}
