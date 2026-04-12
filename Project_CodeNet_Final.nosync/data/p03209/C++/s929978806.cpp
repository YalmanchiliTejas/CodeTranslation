#include <bits/stdc++.h>
using namespace std;

long long c(int n, long long x, vector<long long> a, vector<long long> b) {
	if (x == 1) {
		if (n == 0) return 1;
		else return 0;
	}
	else if (x < a[n - 1] + 2) {
		return c(n - 1, x - 1, a, b);
	}
	else if (x == a[n - 1] + 2) {
		return b[n - 1] + 1;
	}
	else if (x < 2 * a[n - 1] + 3) {
		return b[n - 1] + c(n - 1, x - a[n - 1] - 2, a, b) + 1;
	}
	else {
		return b[n];
	}
}

int main()
{
	int N;
	long long X;
	cin >> N >> X;

	vector<long long> a;
	vector<long long> b;
	long long ax = 1;
	long long bx = 1;
	a.push_back(ax); 
	b.push_back(bx);
	for (int i = 0; i < N; i++) {
		ax = ax * 2 + 3;
		a.push_back(ax);
		bx = bx * 2 + 1;
		b.push_back(bx);
	}

	long long count = c(N, X, a,b);
	cout << count << endl;
	return 0;
}
