#include <bits/stdc++.h>
using namespace std;

long long func(int N, long long X) {
	// レベルNの厚さ:2^(2+N)-3
	// レベルN内のパティ:2^(1+N)-1
	if (N == 0)
		return 1;
	if (X == 1)
		return 0;
	if (1 < X && X < pow(2, 1 + N) - 1)
		return func(N - 1, X - 1);
	if (X == pow(2, 1 + N) - 1)
		return func(N - 1, X - 1) + 1;
	if (X > pow(2, 1 + N) - 1)
		return func(N - 1, X - (pow(2, 1 + N) - 1)) + pow(2, N);
}

int main() {
	int n;
    long long x;
	cin >> n >> x;
	cout << func(n, x) << endl;
}