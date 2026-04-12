#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define sz size()
#define pb push_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int N;

vector<LL> A;

int main() {
	cin >> N;
	A.clear();
	LL x;
	FOR (i, N) {
		cin >> x;
		A.pb(x);
 	}
 	LL ret = 0LL;
 	ffor (len, 1, N) {
 		sort(all(A));
 		reverse(all(A));
 		LL k = (A[len - 1] - A[len]) / (N + 1LL);
 		FOR (i, len) {
 			A[i] -= k * N;
 			A[i] += (len - 1LL) * k;
		}
		if (A[0] <= N && k) {
			FOR (i, len) {
				A[i] += N;
				A[i] -= (len - 1LL);
			}
			k--;
		}
		if (A[0] <= 2 * N && k) {
			FOR (i, len) {
				A[i] += N;
				A[i] -= (len - 1LL);
			}
			k--;
		}

		ffor (i, len, N)
			A[i] += len * k;
		ret += len * k;
		sort(all(A));
		reverse(all(A));
		while (A[0] >= N && A[0] - A[len] >= N) {
			A[0] -= N;
			ffor (i, 1, N)
				A[i]++;
			ret++;
			sort(all(A));
			reverse(all(A));
		}
	}
	LL k = max(0LL, A[0] - 2LL * N);
	FOR (i, N)
		A[i] -= k;
	ret += N * k;
	while (A[0] >= N) {
		A[0] -= N;
		ffor (i, 1, N)
			A[i]++;
		ret++;
		sort(all(A));
		reverse(all(A));
	}
	cout << ret << endl;
	return 0;
}