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

int d;

const int N =  1e4 + 1;

int memo[N][100][2];

int add(int x, int y, int m) {
	return (x + y) % m;
}

int dp() {
	memo[k.size()][0][false] = memo[k.size()][0][true] = 1;
	for(int idx = k.size() - 1; idx >= 0; --idx) {
		for(int smaller = 0; smaller <= 1; ++smaller) {
			for(int sum = 0; sum < d; ++sum) {
				for(int digit = 0; digit < 10; ++digit) {
					if(not smaller and digit > k[idx] - '0')
						continue;
					int &ans = memo[idx][sum][smaller];
					ans = add(memo[idx + 1][add(sum, digit, d)][smaller | (digit < k[idx] - '0')], ans, MOD);
				}
			}
		}
	}
	return memo[0][0][0];
}

int main() {
    Data_Nerd

	cin >> k >> d;

    cout << (dp() - 1 + MOD) % MOD;

    return 0;
}
