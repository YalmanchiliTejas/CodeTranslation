#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string s;
	int a=1;
	cin >> s;
	for (int i = 1; i < 3; i++) {
		if (s[i - 1] == s[i]&&a==1) {
			a = 1;
		}
		else {
			a = 0;
		}
	}
	if (a == 1) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

}