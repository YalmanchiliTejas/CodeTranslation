#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
using namespace std;
vector<long long> p(51);
vector<long long> b(51);
vector<long long> l(51);
long long Count(int N, long long X) {
	if (N == 0) return 1;
	if (X <= N) {
		return 0;
	}
	else if (X <= l[N] / 2) {
		return Count(N - 1, X - 1);
	}
	else if (X <= l[N] / 2 + 2)
		return p[N - 1] + 1;
	else if (X < l[N] - N) {
		return p[N - 1] + 1 + Count(N - 1, X - l[N]/2 - 1);
	}		
	else
		return p[N];
}

int main() {
	long long N, X;
	cin >> N >> X;
	long long cnt = 0;
	int i = 0;
	
	p[0] = 1;
	b[0] = 0;
	l[0] = 1;
	for (int i = 1; i < N + 1; i++) {
		p[i] = p[i - 1] * 2 + 1;
		b[i] = b[i - 1] * 2 + 2;
		l[i] = l[i - 1] * 2 + 3;
	}
	cout << Count(N, X);
	return 0;
}