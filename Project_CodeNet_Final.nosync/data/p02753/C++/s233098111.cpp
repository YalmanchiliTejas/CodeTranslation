#include <iostream>
using namespace std;
int main() {
	int i = 3, x = 0, y = 0;
	char ch;
	while(i--) {
		cin >> ch;
		if(ch =='A') ++x;
		else ++y;
	}
	if((x > 1 && y > 0) || (y > 1 && x > 0)) {
		cout << "Yes" << endl;
	} else cout << "No" << endl;
	return 0;
}