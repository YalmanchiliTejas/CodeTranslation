#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1000000007;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<int> res(N);
	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				res[(N / 2) + i / 2] = a[i];
			}
			else {
				res[(N / 2) - (i+1) / 2] = a[i];
			}
		}
	}else{
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				res[(N / 2) - i / 2] = a[i];
			}
			else {
				res[(N / 2) + (i + 1) / 2] = a[i];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << res[i];
	}
	cout << endl;
	return 0;
	
}