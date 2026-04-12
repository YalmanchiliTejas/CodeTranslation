#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <random>
#include <complex>
#include <assert.h>

using namespace std;
typedef long long ll;
#define endl '\n'

template<typename T>
inline bool chmin(T& x, T a) {
	if (x >= a) { x = a; return true; }
	return false;
}

template<typename T>
inline bool chmax(T& x, T a) {
	if (x <= a) { x = a; return true; }
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);

	ll N, X, M; cin >> N >> X >> M;

	vector<bool> visited(M);

	vector<ll> A;
	A.push_back(X); visited[X] = true;
	ll x = X;
	while (1) {
		x = (x * x) % M;
		if (visited[x]) { break; }
		else { A.push_back(x); visited[x] = true; }
	}
	// x : ループの先頭
	// A : 先頭の部分 + ループ部分

	ll N1 = 0, N2 = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == x) {
			N1 = i;
			N2 = A.size() - N1;
			break;
		}
	}

	ll sum = 0;
	for (int i = N1; i < A.size(); i++) { sum += A[i]; }

	if (N <= A.size()) {
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += A[i];
		}
		cout << sum << endl;
		return 0;
	}
	ll ans = 0;
	for (int i = 0; i < N1; i++) {
		ans += A[i];
	}
	N -= N1;
	ans += sum * (N / N2);
	N %= N2;
	for (int i = N1; i < N1 + N; i++) {
		ans += A[i];
	}

	cout << ans << endl;

	return 0;
}