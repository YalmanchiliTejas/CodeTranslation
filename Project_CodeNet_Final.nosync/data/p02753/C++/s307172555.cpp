#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	while (cin){
		int a = 0, b = 0;
		for (int i = 0; i < 3; ++i){
			if (s[i] == 'A') ++a;
			else ++b;
		}
		if (a == 0 || a == 3) cout << "No\n";
		else cout << "Yes\n";
		cin >> s;
	}
	return 0;
}