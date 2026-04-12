#include <iostream>
using namespace std;
int main() {
	string s;
	int a = 0, b = 0, i = 0;
	cin >> s;
	for(i = 0; i < 3; i++){
	    if(s[i] == 'A') a++;
	    else b++;
	}
	cout << ( a == 3 || b == 3 ? "No" : "Yes") << "\n";
	return 0;
}