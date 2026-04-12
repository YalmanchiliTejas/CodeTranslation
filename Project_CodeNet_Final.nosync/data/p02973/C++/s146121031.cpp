#pragma GCC optimize("Ofast")
#pragma GCC target ("avx")
#include <bits/stdc++.h>

constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

// 5 4 9 8 9
// 5 5 9 9 9 
//   4 4 8 9
//
// 2 1 4 5 3
// 2 2 4 5 5
//   1 1 1 3

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	multiset<int> v;
	v.insert(A[0]);
	for (int i = 1; i < N; i++) {
		auto itr = v.lower_bound(A[i]);
		if (itr == v.begin()) {
			v.insert(A[i]);
		}
		else {
			itr--;
			v.erase(itr);
			v.insert(A[i]);
		}
	}
	cout << v.size() << endl;
}