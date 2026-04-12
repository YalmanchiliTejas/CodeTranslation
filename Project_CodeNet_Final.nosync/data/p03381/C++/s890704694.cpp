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

const int MAXN = 300000;

vector<pair<int, int> > A;

int ret[MAXN];

int N;

int main() {
	ios_base::sync_with_stdio(false);
	A.clear();
	cin >> N;
	int x;
	FOR (i, N) {
		cin >> x;
		A.pb(make_pair(x, i));
	}
	sort(all(A));
	FOR (i, A.sz) {
		if (i < N / 2)
			ret[A[i].second] = A[N / 2].first;
		else
			ret[A[i].second] = A[N / 2 - 1].first;
	}
	FOR (i, N)
		cout << ret[i] << endl;
		
	return 0;
}