#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<limits>
#include<deque>
#include<map>
#include<list>
#include<set>
#include <unordered_set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<memory>
#include<bitset>
#include<stack>
#include<functional>
#include<queue>
#include<regex>
#include<time.h>
#include <iterator>


using namespace std;

using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll INF = 1050000000;

#define index_of(as, x) distance(as.begin(), upper_bound(as.begin(), as.end(), x))

vector<int> lis_fast(const vector<int>& a) {
	const int n = a.size();
	vector<int> A(n, INF);
	vector<int> id(n);
	for (int i = 0; i < n; ++i) {
		id[i] = index_of(A, a[i]);
		A[id[i]] = a[i];
	}
	int m = *max_element(id.begin(), id.end());
	vector<int> b(m + 1);
	for (int i = n - 1; i >= 0; --i)
		if (id[i] == m) b[m--] = a[i];
	return b;
}

int main() {
	int n; cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());

	cout << lis_fast(a).size() << endl;



	return 0;
}
