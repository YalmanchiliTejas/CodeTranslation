#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() {
	int N;
	string S;
	cin >> N;
	vector<int> C(1000, 0), D(1000, 512411);
	for (int i = 0;i < N;i++) {
		cin >> S;
		for (char c : S) {
			C[c]++;
		}
		for (int j = 0;j < 1000;j++) {
			D[j] = min(D[j], C[j]);
			C[j] = 0;
		}
	}
	for (int i = 0;i < 1000;i++) {
		char c = i;
		for (int j = 0;j < D[i];j++) {
			cout << c;
		}
	}
	cout << endl;
}