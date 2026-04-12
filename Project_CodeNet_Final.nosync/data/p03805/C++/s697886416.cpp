#include<iostream>
#include<vector>
using namespace std;
int n, m;
int ans = 0;

int solve(vector<int>a, vector<int>b, vector<int>tmp, int deep) {
	if (deep + 1 == n) {
		ans++;
		return 0;
	}
	for (int i = 0;i < m;i++) {
		if (a[i] == tmp[deep]) {
			for (int j = 0;j <= deep;j++) {
				if (tmp[j] == b[i]) {
					break;
				}
				if (j == deep) {
					tmp[deep + 1] = b[i];
					solve(a, b, tmp, deep + 1);
				}
			}
		}
		if (b[i] == tmp[deep]) {
			for (int j = 0;j <= deep;j++) {
				if (tmp[j] == a[i]) {
					break;
				}
				if (j == deep) {
					tmp[deep + 1] = a[i];
					solve(a, b, tmp, deep + 1);
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;
	vector<int>tmp(2 * n);
	vector<int>a(2 * m);
	vector<int>b(2 * m);
	for (int i = 0;i < m;i++) {
		cin >> a[i] >> b[i];
	}
	tmp[0] = 1;
	solve(a, b, tmp, 0);
	cout << ans << endl;
	return 0;
}