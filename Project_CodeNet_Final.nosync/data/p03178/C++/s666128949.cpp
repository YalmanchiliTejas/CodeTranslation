#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define TR(X) ({ if(1) cerr << "Trace: " << (#X) << " = " << (X) << endl; })
const int P = 1e9 + 7;
const int maxs = 105;
const int amount_digits = 10001;
int dp[amount_digits][maxs][2];

void add_self(int &a, int b) {
	a += b;
	if(a >= P) a -= P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string k;
	int d;
	cin >> k >> d;
	int n = (int) k.size();
	dp[0][0][0] = 1;
	for(int digits = 0; digits < n; digits++) {
		for(int cur_sum = 0; cur_sum < d; cur_sum++) for(int smaller = 0; smaller < 2; smaller++) {
			for(int ndigit = 0; ndigit < 10; ndigit++) {
				if(!smaller && ndigit > k[digits] - '0') break;
				int nsmaller = smaller || ndigit < k[digits] - '0';
				add_self(dp[digits + 1][(cur_sum + ndigit) % d][nsmaller], dp[digits][cur_sum][smaller]);
			}
		}
	}
	TR(dp[n][0][0]);
	cout << (dp[n][0][0] + dp[n][0][1] + P - 1) % P << '\n';
}
