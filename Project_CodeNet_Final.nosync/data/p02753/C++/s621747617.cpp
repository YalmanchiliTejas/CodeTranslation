#include <iostream>
#include <string>

using namespace std;

int main (){
	
	char s[3];
	int i,j=0;
	
	cin >> s[0]>>s[1]>>s[2];

	if (s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	

	return 0;
}