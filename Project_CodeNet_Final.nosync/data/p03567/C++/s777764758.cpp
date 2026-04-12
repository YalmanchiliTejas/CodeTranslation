#include"bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	for (int i = 0;i < S.size() - 1;++i) {
		if (S[i] == 'A' && S[i + 1] == 'C') {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}