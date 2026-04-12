#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	char flag = S.at(K - 1);
	rep(i, N) {
		if (S.at(i) != flag) S.at(i) = '*';
	}
	cout << S << endl;
	return 0;
}