#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, l, r;
	while (cin >> n >> l >> r, n | l | r) {
		r += 1;
		vector<int> A(n);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		vector<int> v(r, n % 2 == 0);
		for (int i = n - 1; i >= 0; i--) {
			for (int j = A[i]; j < r; j += A[i]) {
				v[j] = i % 2 == 0;
			}
		}
		cout << count(v.begin() + l, v.begin() + r, 1) << endl;
	}
	return 0;
}

