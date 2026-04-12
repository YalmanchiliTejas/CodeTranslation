#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin >> s;
	if ((s[1]==s[0]&&s[1]!=s[2])||(s[1]!=s[0]&&s[1]==s[2])||(s[1]!=s[0]&&s[1]!=s[2])) cout << "Yes";
	else cout << "No";
	return 0;
}