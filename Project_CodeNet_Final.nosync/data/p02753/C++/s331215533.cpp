#include <iostream>
using namespace std;

int main(){ 
	string s;
	cin >> s;
	if(s[1] != s[2] || s[1] != s[0])
		cout << "Yes";
	else
		cout << "No";
}
