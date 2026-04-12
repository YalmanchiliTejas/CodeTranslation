#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	string S;

	cin >> S;

	int s = 0;
	bool flag = false;

	char str = S[s];

	for (int i = 1; i < (int)S.size(); ++i) {
		if (str != S[i]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}