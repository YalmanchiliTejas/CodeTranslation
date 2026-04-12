#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	if (S.find("AC") == string::npos) cout << "No";
	else cout << "Yes";
}