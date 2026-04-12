#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;

#define REP(i,n) for(int i=0;(i)<(n);(i)++)

int main() {
	int n, a[200005];
	deque<int> dq;
	cin >> n;
	REP(i, n) {
		cin >> a[i];
	}

	if (n % 2 == 0) {
		for(int i=0;i<n;i+=2) {
			dq.push_back(a[i]);
			dq.push_front(a[i + 1]);
		}
	}
	else {
		for (int i = 0;i < n - 1;i += 2) {
			dq.push_front(a[i]);
			dq.push_back(a[i+1]);
		}
		dq.push_front(a[n - 1]);
	}

	REP(i, n) {
		if (i > 0) cout << " ";
		cout << dq[i];
	}

	cout << endl;
	return 0;
}