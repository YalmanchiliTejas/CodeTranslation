#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin >> s;
	bool x = false;
	if (s[0] != s[1]) x = true;
	if (s[1] != s[2]) x = true;
	if (s[2] != s[0]) x = true;
	if (x) cout << "Yes" << endl;
	else cout<<"No"<<endl;
}