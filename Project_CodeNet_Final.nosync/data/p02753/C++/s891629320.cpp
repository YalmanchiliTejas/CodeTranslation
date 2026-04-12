#include <iostream>
using namespace std;
int main(){
	char s[4];
	cin >> s;
	if(s[0] != s[1] || s[1] != s[2])
		cout << "Yes\n";
	else
		cout << "No\n";
}
