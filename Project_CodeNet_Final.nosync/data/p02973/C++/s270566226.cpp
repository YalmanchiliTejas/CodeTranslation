#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N, A[100000], res;
multiset<int>st;

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		auto it = st.lower_bound(A[i]);
		if (it == st.begin()) {
			++res;
			st.insert(A[i]);
		}
		else {
			--it;
			st.erase(it);
			st.insert(A[i]);
		}
	}
	cout << res << endl;
}