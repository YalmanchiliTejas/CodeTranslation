#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B;
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	B = A;
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {

		if (B[i] <= A[(N / 2) - 1]) {
			cout << A[(N / 2)] << endl;
		}
		else {
			cout << A[(N / 2) - 1] << endl;
		}
	}
	
}