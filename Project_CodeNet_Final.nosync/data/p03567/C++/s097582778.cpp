#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	string S;
	cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S.substr(i, 2) == "AC") {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}
