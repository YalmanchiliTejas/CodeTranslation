//============================================================================
// Name        : competitive_programing.cpp
// Author      : .Data_Nerd.
// Description : problem solving training
//============================================================================

#include <bits/stdc++.h>
#define Data_Nerd ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define files freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define MOD 1000000007
#define OO 0x3f3f3f3f
#define NIL -1
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <bool> lala;
typedef pair<int, int> piaz;
typedef vector<vector<int>> board;
typedef priority_queue <piaz, vector <piaz>, greater<piaz>> wMinPQ;
typedef priority_queue <int, vector <int>, greater<int>> minPQ;
template <typename T> T GCD(T a, T b) { return !a ? b : GCD(b % a, a); }
template <typename T> T LCM(T a, T b) { return (a * b) / GCD(a, b); }
template <typename T>
T fastPower(T base, T power) {
	if(!power)
		return 1;
	T ans = fastPower(base, power >> 1);
	return power & 1 ? ans * ans * base : ans * ans;
}
template <typename T>
T modPower(T base, T power, T m = MOD) {
	if(!power)
		return 1;
	T ans = modPower(base, power >> 1) % m;
	return power & 1 ? (((ans * ans) % m) * (base % m)) % m : (ans * ans) % m;
}

string k;

int d, size;

const int N =  1e4;

int memo[N][100][2];

int add(int x, int y, int m) {
	return (x + y) % m;
}

int dp(int idx = 0, int sum = 0, bool isLess = false) {
	if(idx == size)
		return sum == 0;
	int &ans = memo[idx][sum][isLess];
	if(ans != NIL)
		return ans;
	ans = 0;
	for(int i = 0; i < 10; ++i) {
		if(not isLess and i > k[idx] - '0')
			continue;
		bool smaller;
		if(isLess)
			smaller = true;
		else if(i < k[idx] - '0')
			smaller = true;
		else
			smaller = false;
		ans = add(dp(idx + 1, add(sum, i, d), smaller), ans, MOD);
	}
	return ans;
}

int main() {
    Data_Nerd

	cin >> k >> d;
    size = k.size();
    memset(memo, NIL, sizeof memo);

    cout << (dp() - 1 + MOD) % MOD;

    return 0;
}
