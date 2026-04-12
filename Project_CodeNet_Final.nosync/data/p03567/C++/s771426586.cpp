#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	if (str.find("AC") != str.npos)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}