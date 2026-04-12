#include <bits/stdc++.h>
using namespace std;

multiset<int> S;

int main() {
	int N, A, cnt = 0;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> A;
		auto it = S.lower_bound(A);
		if (it == S.begin()) {
			cnt++;
			S.insert(A);
		}
		else {
			it--;
			S.erase(it);
			S.insert(A);
		}
	}
	cout << cnt << endl;
}