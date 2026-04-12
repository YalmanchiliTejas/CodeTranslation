#include <iostream>
#include <string>
using namespace std;

int main()
{
	string c;
	bool flag=false;
	cin >> c;

	for (int i=0; i<c.size();i++) {
	char target=c[i];
		if (target == 'a' || target == 'i' || target == 'u' || target == 'e' || target == 'o') {
			flag = true;
		}
	}

	if (flag) {
		cout << "vowel";
	}else {
		cout << "consonant";
	}
	return 0;
}