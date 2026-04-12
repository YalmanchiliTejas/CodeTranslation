#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
int A[100000];
 int main() {
	 int N;
	 cin >> N;
	 for (int i = 0; i < N; i++) cin >> A[i];
	 multiset<int> S;
	 for (int i = N - 1; i >= 0; i--) {
		 auto itr = S.upper_bound(A[i]);
		 if (itr == S.end()) {
			 S.insert(A[i]);
		 }
		 else {
			 S.erase(itr);
			 S.insert(A[i]);
		 }
	 }
	 cout << S.size() << endl;
}