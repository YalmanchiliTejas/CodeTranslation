#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;
int dp[10005][105][2];

void mod_self(int& a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0) 
		a += mod;
}

int main() {
	string num;
	int d, size;
	cin >> num >> d;
	size = num.size();
	dp[0][0][1] = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < d; j++) {
			for (int l = 0; l < 10; l++) {
				int to = (j + l) % d;
				
				if (dp[i][j][1]) {
					if (l == num[i] - '0') {
						mod_self(dp[i + 1][to][1], dp[i][j][1]);
					} else if (l < num[i] - '0') {
						mod_self(dp[i + 1][to][0], dp[i][j][1]);
					}
				}
				
				if (dp[i][j][0]) {
					mod_self(dp[i + 1][to][0], dp[i][j][0]);
				}
			}
		}
	}
	cout << (dp[size][0][0] + dp[size][0][1] - 1 + mod) % mod << endl;
}