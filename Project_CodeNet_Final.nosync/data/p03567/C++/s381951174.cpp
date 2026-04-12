#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	cin >> S;
	if (S.find("AC") != string::npos) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}