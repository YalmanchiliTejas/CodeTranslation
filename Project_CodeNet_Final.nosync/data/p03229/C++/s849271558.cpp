//
// Created by zono on 18/10/27.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 2) {
		cout << abs(a[0] - a[1]) << endl;
		return 0;
	}
	sort(a, a + n);
	vector<int> A;
	A.push_back(a[0] + a[0]);
	bool flag = false;
	long ans1 = 0, ans2 = 0;
	int left = 1, right = n - 1;

	while (left <= right - 1) {
		A.push_back(a[right] + a[right - 1]);
		if (left + 1 < right - 1) A.push_back(a[left] + a[left + 1]);
		else if (left != right - 1) ans1 += max(abs(a[left] - a[left + 1]), abs(a[left] - a[left + 2]));
		left += 2, right -= 2;
	}
	if (left == right) ans1 += max(abs(a[right] - a[right - 1]), abs(a[right] - a[right - 2]));
	for (int i = 0; i < A.size() - 1; i++) {
		ans1 += abs(A[i] - A[i + 1]);
	}

	reverse(a, a + n);

	vector<int> B;
	B.push_back(a[0] + a[0]);
	left = 1, right = n - 1;
	while (left <= right - 1) {
		B.push_back(a[right] + a[right - 1]);
		if (left + 1 < right - 1) B.push_back(a[left] + a[left + 1]);
		else if (left != right - 1) ans2 += max(abs(a[left] - a[left + 1]), abs(a[left] - a[left + 2]));
		left += 2, right -= 2;
	}
	if (left == right) ans2 += max(abs(a[right] - a[right - 1]), abs(a[right] - a[right - 2]));
	for (int i = 0; i < B.size() - 1; i++) {
		ans2 += abs(B[i] - B[i + 1]);
	}

	cout << max(ans1, ans2) << endl;
	return 0;
}