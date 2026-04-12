#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n,x;
	cin >> n >> x;

	vector<vector<long long>> b(n + 1, vector<long long>(5, 0));
	vector<long long> p(n + 1, 0);

	b[0] = { 0,0,1,0,0 };
	p[0] = 1;
	for (int i = 1; i < n+1; i++) {
		b[i][0] = 1;
		b[i][2] = 1;
		b[i][4] = 1;
		b[i][1] = b[i - 1][0] + b[i - 1][1] + b[i - 1][2] + b[i - 1][3] + b[i - 1][4];
		b[i][3] = b[i][1];
		p[i] = p[i - 1] * 2 + 1;
	}

	long long total = 0;
	long long totalp = 0;
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < 5; j++) {
			total += b[i][j];
			if (total == x) {
				if (j == 0) {cout << totalp << endl;}
				if (j == 1) { cout << totalp + p[i - 1] << endl; }
				if (j == 2) { cout << totalp + p[i - 1] + 1 << endl; }
				if (j == 3) { cout << totalp + 2 * p[i - 1] + 1 << endl; }
				if (j == 4) { cout << totalp + 2 * p[i - 1] + 1 << endl; }
				return 0;
			}
			else if (total > x) {
				total -= b[i][j];
				if (j == 3) { 
					totalp += p[i - 1]+1;
				}
				break;
			}
		}
	}

}