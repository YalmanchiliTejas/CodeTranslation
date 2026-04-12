#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#pragma warning(disable: 4996)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep2(j,a,b) for(int j = a; j < (b); j++)
using namespace std;
using ll = long long;

int main() {

	int N;
	int k = 0;
	cin >> N;
	vector<int> d(N);

	rep(i, N) {
		cin >> d[i];
		if (k - 10 > d[i]) {
			k -= 10;
		}
		else if (k - 10 <= d[i]) {
			k = d[i];
		}

		if (k < 10) {
			cout << "no" << endl;
			return 0;
		}
	}
	k = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (k - 10 > d[i]) {
			k -= 10;
		}
		else if (k - 10 <= d[i]) {
			k = d[i];
		}

		if (k < 10) {
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;

}
