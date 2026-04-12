#include <iostream>
using namespace std;
int main()
{
	char s;
	bool flag = true;
	cin >> s;
	char arr[5] = {'a', 'e', 'i', 'o', 'u'};
	for (int i = 0; i < 5; i++) {
		if (s == arr[i]) {
			cout << "vowel" << endl;
			flag = false;
			break;
		}
		
	}
	if (flag) {
		cout << "consonant" << endl;
	}
	return 0;
}
