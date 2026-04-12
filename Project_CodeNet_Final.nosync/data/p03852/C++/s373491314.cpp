#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string s = "aiueo";
	string c;
	cin >> c;
	s.find(c) != string::npos ?  cout << "vowel" : cout << "consonant" ;
	cout << endl;

	return 0;
}
