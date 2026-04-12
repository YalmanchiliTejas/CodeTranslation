#include<iostream>
#include<string>
using namespace std;
int main() {
	string i;
	string s = "Yes";
	cin >> i;
	if (i[0] == i[1] && i[2] == i[1]) {
		s = "No";
	}
	cout << s << endl;
}
