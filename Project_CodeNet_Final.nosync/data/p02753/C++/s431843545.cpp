#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3;

char S[N + 2];

int main() {
	cin >> S;
	int m = 0;
	for(int i = 0; i < N; i++)
		m |= 1 << S[i] - 'A';
	if(m == 3)
		cout << "Yes" << '\n';
	else
		cout << "No" << '\n';
}
