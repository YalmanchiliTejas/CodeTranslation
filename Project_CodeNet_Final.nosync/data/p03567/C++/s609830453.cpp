//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	string s;
	cin >> s;
	int flag = 0;
	for (int i = 0; i < s.size()-1; i++) {
		if ((s[i] == 'A') && (s[i + 1] == 'C')) {
			flag = 1;
			break;
		}
	}
	if (flag==1) {
		cout << "Yes"<<endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}