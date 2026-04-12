#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

vector<long long> a(52,1),p(52,1);

long long f(int x, long long N) {
	if (x < 1) return 1;
	else if (N<=1) return 0;
	else if (1 < N&&a[x - 1]+1 >= N) return f(x - 1, N - 1);
	else if (N == 2 + a[x - 1])return 1 + p[x - 1];
	else if (2 + a[x - 1] <N && 2 + 2 * a[x - 1] >= N) return p[x - 1] + 1 + f(x - 1, N - 2 - a[x - 1]);
	else return p[x];
}


int main() {
	int N; long long X; cin >> N >> X;
	for (int i = 0; i <= 50; i++) {
		a[i + 1] = 2*a[i] + 3;
		p[i + 1] = 2*p[i] + 1;
	}
	cout << f(N, X) << endl;;
}

