#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int main() {
	string S; cin >> S;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S.substr(i, 2) == "AC") { cout << "Yes" << endl; return 0; }
	}
	cout << "No" << endl;
	return 0;
}