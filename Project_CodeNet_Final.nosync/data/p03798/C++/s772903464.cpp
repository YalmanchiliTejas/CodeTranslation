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
	ll N;
	string s;
	cin >> N>>s;
	vector<bool> A(N)/*true='o' false='x'*/;
	rep(i, N) {
		if (s[i] == 'x')A[i] = false;
		else A[i] = true;
	}
	vector<bool> animal(N);/*true=sheep false=wolf*/
	animal[0] = true;
	animal[1] = true;
	for (ll i = 2; i < N; i++) {
		if (animal[i - 1]) {
			if (A[i - 1])animal[i] = animal[i - 2];
			else animal[i] = !animal[i - 2];
		}
		else {
			if (A[i - 1])animal[i] = !animal[i - 2];
			else animal[i] = animal[i - 2];
		}
	}
	bool ch = true;
	bool sh = true;
	if (animal[N - 1] && A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (animal[N - 1] && !A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else if (!animal[N - 1] && !A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (!animal[N - 1] && A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else ch = false;

	if (animal[0] && A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (animal[0] && !A[0] && (animal[N - 1] != animal[1]))sh = true;
	else if (!animal[0] && !A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (!animal[0] && A[0] && (animal[N - 1] != animal[1]))sh = true;
	else sh = false;
	if (ch&&sh) {
		rep(i, N) {
			if (animal[i])cout << 'S';
			else cout << 'W';
		}
		return 0;
	}

	animal[0] = false;
	animal[1] = true;
	for (ll i = 2; i < N; i++) {
		if (animal[i - 1]) {
			if (A[i - 1])animal[i] = animal[i - 2];
			else animal[i] = !animal[i - 2];
		}
		else {
			if (A[i - 1])animal[i] = !animal[i - 2];
			else animal[i] = animal[i - 2];
		}
	}
	ch = true, sh = true;
	if (animal[N - 1] && A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (animal[N - 1] && !A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else if (!animal[N - 1] && !A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (!animal[N - 1] && A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else ch = false;

	if (animal[0] && A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (animal[0] && !A[0] && (animal[N - 1] != animal[1]))sh = true;
	else if (!animal[0] && !A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (!animal[0] && A[0] && (animal[N - 1] != animal[1]))sh = true;
	else sh = false;

	if (ch&&sh) {
		rep(i, N) {
			if (animal[i])cout << 'S';
			else cout << 'W';
		}
		return 0;
	}

	animal[0] = true;
	animal[1] = false;
	for (ll i = 2; i < N; i++) {
		if (animal[i - 1]) {
			if (A[i - 1])animal[i] = animal[i - 2];
			else animal[i] = !animal[i - 2];
		}
		else {
			if (A[i - 1])animal[i] = !animal[i - 2];
			else animal[i] = animal[i - 2];
		}
	}
	ch = true, sh = true;
	if (animal[N - 1] && A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (animal[N - 1] && !A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else if (!animal[N - 1] && !A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (!animal[N - 1] && A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else ch = false;

	if (animal[0] && A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (animal[0] && !A[0] && (animal[N - 1] != animal[1]))sh = true;
	else if (!animal[0] && !A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (!animal[0] && A[0] && (animal[N - 1] != animal[1]))sh = true;
	else sh = false;

	if (ch && sh) {
		rep(i, N) {
			if (animal[i])cout << 'S';
			else cout << 'W';
		}
		return 0;
	}

	animal[0] = false;
	animal[1] = false;
	for (ll i = 2; i < N; i++) {
		if (animal[i - 1]) {
			if (A[i - 1])animal[i] = animal[i - 2];
			else animal[i] = !animal[i -2];
		}
		else {
			if (A[i - 1])animal[i] = !animal[i - 2];
			else animal[i] = animal[i - 2];
		}
	}
	ch = true, sh = true;
	if (animal[N - 1] && A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (animal[N - 1] && !A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else if (!animal[N - 1] && !A[N - 1] && (animal[N - 2] == animal[0]))ch = true;
	else if (!animal[N - 1] && A[N - 1] && (animal[N - 2] != animal[0]))ch = true;
	else ch = false;

	if (animal[0] && A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (animal[0] && !A[0] && (animal[N - 1] != animal[1]))sh = true;
	else if (!animal[0] && !A[0] && (animal[N - 1] == animal[1]))sh = true;
	else if (!animal[0] && A[0] && (animal[N - 1] != animal[1]))sh = true;
	else sh = false;

	if (ch && sh) {
		rep(i, N) {
			if (animal[i])cout << 'S';
			else cout << 'W';
		}
		return 0;
	}

	cout << -1 << endl;
}