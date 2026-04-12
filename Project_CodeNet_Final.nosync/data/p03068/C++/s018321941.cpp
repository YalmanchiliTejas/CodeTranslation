#include <iostream>
using namespace std;

int main() {
	int N, K;
	string S;
	cin >> N >> S >> K;
	char t = S[K - 1];
	for (char& c : S) if (c != t) c = '*';
	cout << S << endl;
}