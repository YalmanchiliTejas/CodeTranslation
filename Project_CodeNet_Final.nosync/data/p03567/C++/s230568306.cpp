#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int mozisu = s.length();
	int flag = 0;
	for (int i = 0; i < mozisu-1; i++) {
		if (s[i] == 'A'&&s[i + 1] == 'C') {
			flag = 1;
		}
	}
	if (flag == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}