#include<functional>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string.h>
#include <string>
#include <math.h>
#include <time.h>
#include <vector>
#include <queue>
#include<stack>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int n, d;
string s;
int dp[10001][2][100];
int calc(int idx, bool lmt, int sum) {
	if (idx == n) {
		if (sum == 0)
			return 1;
		return 0;
	}
	int &ret = dp[idx][lmt][sum];
	if (ret != -1)
		return ret;
	ret = 0;
	if (lmt) {
		for (int i = 0; i < s[idx] - '0'; ++i)
			ret = (ret + calc(idx + 1, false, (sum + i) % d)) % mod;
		ret = (ret + calc(idx + 1, true, (s[idx] - '0' + sum) % d)) % mod;
	}
	else
		for (int i = 0; i < 10; ++i)
			ret = (ret + calc(idx + 1, false, (sum + i) % d)) % mod;
	return ret;
}
int main() {
	//freopen("src.txt", "r", stdin);
	memset(dp, -1, sizeof dp);
	cin >> s >> d;
	n = s.size();
	int ans = 0;
	for (int i = 0; i < s[0] - '0'; ++i)
		ans = (ans + calc(1, false, i % d)) % mod;
	ans = (ans + calc(1, true, (s[0] - '0') % d)) % mod;
	cout << (ans - 1 + mod) % mod << endl;
	return 0;
}