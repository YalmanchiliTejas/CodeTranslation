#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s, t) for(int i = s; i < t; i++)
#define ALL(a)  a.begin(), a.end()
#define SZ(x) (int)x.size()
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define SORT(a) sort(ALL(a))
using VI = vector<int>;


int main() {

	int N, K; cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI b = a;
	SORT(a);
	int m1 = a[N / 2 - 1];
	int m2 = a[N / 2];

	FOR(i, 0, N) {
		cout << ((b[i] < m2) ? m2 : m1) << endl;
	}
	return 0;
}
