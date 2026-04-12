#include <bits/stdc++.h>

using namespace std;

#define N 3001

typedef long long ll;

ll pg[N][N];


int main() {
	int n;

	cin >> n;

	int a[n];

	for (int i = 0;i < n;i++) {
		cin >> a[i];
		pg[i][i] = a[i];
	}

	for (int i = 1;i < n;i++) {

		int I = 0;

		for (int j = i;j < n;j++) {
			ll p1 = pg[I][I] - pg[I + 1][j];
			ll p2 = pg[j][j] - pg[I][j - 1];

			if (p1 > p2) {
				pg[I][j] = p1;
			} else {
				pg[I][j] = p2;
			}	

			I++;
		}

	}

	cout << pg[0][n - 1];
}
