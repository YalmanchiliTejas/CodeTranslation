#include <bits/stdc++.h>

constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N,K;
	string S;
	cin >> N >> S >> K;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] != S[K - 1])S[i] = '*';
	}
	cout << S << endl;
}