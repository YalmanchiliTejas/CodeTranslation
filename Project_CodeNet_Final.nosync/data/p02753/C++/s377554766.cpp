#include<iostream>

using namespace std;
int main() {
	char* S = new char[3];
	bool flag = true;

	cin >> S;

	for (int i = 0; i < 2; i++) {
		if (S[i] != S[i + 1]) {
			flag = false;
			cout << "Yes" << endl;
			break;
		}
	}

	if(flag)
		cout << "No" << endl;

	return 0;
}