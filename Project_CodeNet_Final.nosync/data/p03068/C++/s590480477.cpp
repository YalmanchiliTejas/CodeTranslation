#include <bits/stdc++.h>
#include <stdint.h>
#include <algorithm>

using namespace std;

int main() {
	int N;
	string S;
	int K;
	cin >> N >> S >> K;
	
	K--;
	
	char same = S.at(K);
	
	for (int i = 0; i < N; i++) {
		if (S.at(i) == same) {
		} else {
			S.at(i) = '*';
		}
	}
	
	cout << S << endl;
	
	
	return 0;
}
