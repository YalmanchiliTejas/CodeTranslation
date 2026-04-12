#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N,K;
	char A;
	string S;
	cin >> N >> S >> K;
	K--;
	string SS;
	A = S[K];
	for (int i = 0; i < N; i++) {
		if (S[i] == S[K]) {
			SS.push_back(A);
		}
		else SS.push_back('*');
	}
	cout << SS << endl;
}