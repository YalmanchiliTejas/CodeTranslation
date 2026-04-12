#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<char> P(N);
	for (char& i : P) cin >> i;
	char ans = P.front();
	for (int i = 1; i < N; ++i) {
		if ('F' == P[i] && 'T' == ans) ans = 'F';
		else ans = 'T';
	}
	cout << ans << endl;
}
