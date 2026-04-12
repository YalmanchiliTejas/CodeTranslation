#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	vector<char> station(3);

	cin >> S;

	for (int i = 0; i < 3; i++) {
		station.at(i) = S.at(i);
	}

	if ((station.at(0) == station.at(1)) &&
		 station.at(1) == station.at(2)) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
}