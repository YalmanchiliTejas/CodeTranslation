#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	cin >> S;

	bool flag = false;
	for(int i = 0; i < S.size(); i++) {
		if(i < S.size() - 1 && S[i] == 'A' && S[i + 1] == 'C') {
			flag = true;
		}
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}
