#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string S;
	cin >> S;

	bool fA = false;
	bool fB = false;
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'A') {
			fA = true;
		}
		else if (S[i] == 'B') {
			fB = true;
		}
	}

	if (fA && fB) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}



