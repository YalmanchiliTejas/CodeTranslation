#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 998244353;

int main() {
	int N, K;
	string S;
	cin >> N;
	cin >> S;
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (S[i] != S[K - 1]) S[i] = '*';
	}
	cout << S << endl;
}