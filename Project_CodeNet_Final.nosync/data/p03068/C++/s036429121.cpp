#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;

	char ch = S[K - 1];
	for (int i = 0; i < N; i++) {
		if (S[i] != ch) cout << '*';
		else cout << S[i];
	}
	cout << endl;
}