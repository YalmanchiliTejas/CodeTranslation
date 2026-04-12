#include <bits/stdc++.h>
using namespace std;


int main() {

	int N;
	string S;
	int K;

	cin >> N;
	cin >> S;
	cin >> K;


	int key = S.at(K - 1);


	for (int i = 0; i < N; i++) {
	
		if (S.at(i) != key) {
			S.at(i) = '*';
		}
	}

	cout << S << endl;
	
}