#include <iostream>
#include <string>

using namespace std;

bool solve(const string& S)
{
	const int L = S.size();
	for (int i = 0; i + 1 < L; ++i) {
		if (S.substr(i, 2) == "AC") {
			return true;
		}
	}
	return false;
}

int main()
{
	string S;
	cin >> S;
	if (solve(S)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

