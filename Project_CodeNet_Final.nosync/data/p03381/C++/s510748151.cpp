#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int iinf = 1 << 29;
const int imax = ~(1 << 31);
const long long linf = 1ll << 61;
const long long lmax = ~(1ll << 63);

#define dump(x) cerr << #x << " : " << x << '\n'
#define MOD(x, y) (((y) + (x) % (y)) % (y))

int N;
pii X[200000];
int rep[200000];

int main(int argc, char* argv[])
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &X[i].first);
		X[i].second = i;
	}
	sort(X, X + N);
	for (int i = 0; i < N; i++) {
		rep[X[i].second] = i;
	}
	for (int i = 0; i < N; i++) {
		int j = rep[i];
		int mid;
		if (2 * j < N) {
			mid = X[N / 2].first;
		} else {
			mid = X[N / 2 - 1].first;
		}
		printf("%d\n", mid);
	}

	return 0;
}
