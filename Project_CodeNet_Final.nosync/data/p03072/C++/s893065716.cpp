#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<cstdlib>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>

using namespace std;

long long dp[3][100100] = {};
const long long INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

long long int a[3][100001];

int main() {
	int n;
	cin >> n;
	int maxer = 0, a, cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (maxer <= a) cnt++;
		maxer = max(maxer, a);
	}
	cout << cnt << endl;
}
