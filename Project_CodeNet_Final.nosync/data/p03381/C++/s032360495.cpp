#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;
typedef pair<int, int> P;

#define pi 3.141592653589793)
#define mod 1000000007

int N;
int a[200001], c[200001];

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) c[i] = a[i];
	sort(a, a + N);
	
	for (int i = 0; i < N; i++) {
		int b = a[N / 2 - 1];
		if (b >= c[i]) b = a[N / 2];
		cout << b << endl;
	}
}

int main() {
	solve();
	return 0;
}