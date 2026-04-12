#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
typedef long long ll;
typedef unsigned long long ull;

int A[100000];
int colors[100000];

int main()
{
	int N;
	int head = 99999, tail = 100000;

	cin >> N;
	rep(i, N) cin >> A[i];

	rep(i, N) {
		if (i == 0) {
			colors[head] = A[i];
			continue;
		}
		else if (A[i] <= colors[head]) {
			head--;
			colors[head] = A[i];
		}
		else {
			int* it = lower_bound(colors + head, colors + tail, A[i]);
			it--;
			*it = A[i];
		}
	}

	cout << tail - head << endl;

	return 0;
}
