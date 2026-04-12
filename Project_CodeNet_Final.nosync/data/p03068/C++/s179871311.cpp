#include <bits/stdc++.h>
using namespace std;

int main() {

	int N;
	cin >> N;

	string  S;
	cin >> S;
	int c;
	cin >> c;
	char C;

	C = S.at(c - 1);
	

	for (int i = 0; i < N; i++) {
		if (S.at(i) != C) {
			S.at(i) = '*';
		}
	}
	cout << S << endl;
}
