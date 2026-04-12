#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long> A(N), a(N), b(N);
	for (long& i : A) cin >> i;
	sort(A.begin(), A.end());
	vector<long> c(A.begin(), next(A.begin(), (N + 1) / 2));
	vector<long> d(next(A.begin(), (N + 1) / 2), A.end());
	a.front() = c.back();
	c.pop_back();
	if (N % 2) {
		if (!c.empty()) {
			a.back() = c.back();
			c.pop_back();
		}
	}
	else {
		a.back() = d.front();
		d.erase(d.begin());
	}
	for (int i = 1; i < N - 1; i++) {
		if (i % 2) {
			a[i] = d.back();
			d.pop_back();
		}
		else {
			a[i] = c.back();
			c.pop_back();
		}
	}

	vector<long> e(A.begin(), next(A.begin(), N / 2));
	vector<long> f(next(A.begin(), N / 2), A.end());
	b.front() = f.front();
	f.erase(f.begin());
	if (N % 2) {
		if (!f.empty()) {
			b.back() = f.front();
			f.erase(f.begin());
		}
	}
	else {
		b.back() = e.back();
		e.pop_back();
	}
	for (int i = 1; i < N - 1; i++) {
		if (i % 2) {
			b[i] = e.back();
			e.pop_back();
		}
		else {
			b[i] = f.back();
			f.pop_back();
		}
	}
	pair<long, long> g;
	for (int i = 1; i < N; i++) {
		g.first += abs(a[i - 1] - a[i]);
		g.second += abs(b[i - 1] - b[i]);
	}
	cout << max(g.first, g.second);
}