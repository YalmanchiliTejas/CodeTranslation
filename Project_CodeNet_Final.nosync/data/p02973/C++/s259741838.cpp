#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	deque<int> clr;
	clr.push_back(A[0]);
	for (int i = 1; i < N; i++) {
		if (A[i] <= clr[0]) {
			clr.push_front(A[i]);
		}
		else {
			if (clr.size() == 1) {
				clr[0] = A[i];
			}
			else {
				int it = lower_bound(clr.begin(), clr.end(), A[i])
					- clr.begin() - 1;
				clr[it] = A[i];
			}
		}
	}
	/*
	for (int i = 0; i < clr.size(); i++) {
		cout << clr[i] << " ";
	}
	cout << endl;
	*/
	cout << clr.size() << endl;
}
