#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

int oknum;
int change(long long int&a, const long long  int to) {
	int plus = 0;
	if (a == 0)plus--;
	if (to == 0)plus++;
	a = to;
	oknum += plus;
	return plus;
}

int main() {
	int N; cin >> N;
	vector<long long int>as(N/2);
	vector<long long int>sums(N/2+1);
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		if (i >= N / 2) {
			as[N - i - 1] -= a;
		}
		else {

			as[i] += a;
		}
	}
	as.insert(as.begin(), 0);
	for (int i = 0; i < N/2; ++i) {
		sums[i] = as[i + 1] - as[i];
	}
	sums[N / 2] = -as[N / 2];
	oknum = count(sums.begin(), sums.end(), 0ll);
	int Q; cin >> Q;
	while (Q--) {
		long long int l, r, x;
		cin >> l >> r >> x;
		l--;
		{
			if (l >= N / 2) {
				change(sums[N - l], sums[N-l]+x);
			}
			else {
				change(sums[l], sums[l] + x);
			}
		}
		{
			if (r >= N / 2) {
				change(sums[N-r], sums[N-r] - x);
			}
			else {
				change(sums[r], sums[r] -x);
			}
		}
		if (oknum == N / 2+1)cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}