#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;
	char x = S.at(0);
	if (S.at(1) == S.at(0) && S.at(2) == S.at(0)) cout << "No" << endl;
	else cout << "Yes" << endl;
}