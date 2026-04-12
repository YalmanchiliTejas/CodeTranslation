#include <iostream>
#include <string>
using namespace std;

int main()
{
	while (true) {
		string str;
		string leftstr = "qwertasdfgzxcvb";
		cin >> str;

		if (str == "#") {
			break;
		}

		int count = 0;
		bool left;

		for (unsigned int i = 0; i < str.size(); i++) {
			bool flag = false;
			for (unsigned int j = 0; j < leftstr.size(); j++) {
				if (str[i] == leftstr[j]) {
					flag = true;
					break;
				}
			}

			if (i == 0) {
				left = flag;
			}
			else {
				if (left != flag) {
					count++;
					left = flag;
				}
			}
		}

		cout << count << endl;
	}

	return 0;
}