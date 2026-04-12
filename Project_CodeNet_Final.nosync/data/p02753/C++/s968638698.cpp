#include<iostream>
#include<stdio.h>

using namespace std;
int main() {
	string s;
	cin >> s;


	int ans = 1;
	for (int i = 0; i < 2; i++) {
		if (s.at(i) != s.at(i + 1)) ans = 0;
	}

	if (!ans) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
