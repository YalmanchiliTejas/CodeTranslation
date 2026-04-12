#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long> A(N), a, b;
	for (long& i : A) cin >> i;
	sort(A.begin(), A.end());
	vector<long> c(A.begin(), next(A.begin(), (A.size() + 1) / 2));
	if (1 < c.size()) swap(c.front(), c[c.size() - 2]);
	vector<long> d(next(A.begin(), (A.size() + 1) / 2), A.end());
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			a.push_back(d.back());
			d.pop_back();

		}
		else {
			a.push_back(c.back());
			c.pop_back();
		}
	}
	long e = 0, f = 0;
	for (int i = 1; i < N; i++) e += abs(a[i - 1] - a[i]);
	vector<long> g(A.begin(), next(A.begin(), A.size() / 2));
	vector<long> h(next(A.begin(), A.size() / 2), A.end());
	if (1 < h.size()) swap(h[1], h.back());
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			b.push_back(g.back());
			g.pop_back();
		}
		else {
			b.push_back(h.back());
			h.pop_back();
		}
	}
	for (int i = 1; i < N; i++) f += abs(b[i - 1] - b[i]);
	cout << max(e, f);
}