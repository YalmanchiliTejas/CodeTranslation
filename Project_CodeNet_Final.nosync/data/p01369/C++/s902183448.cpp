#include <iostream>
using namespace std;

int main()
{
	string str;
	while (cin >> str, str != "#") {
		int hand = -1, res = -1;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'y' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' || str[i] == 'p'
				|| str[i] == 'h' || str[i] == 'j' || str[i] == 'k' || str[i] == 'l' || str[i] == 'n' || str[i] == 'm') {
				if (hand != 0) {
					hand = 0;
					res++;
				}
			}
			else {
				if (hand != 1) {
					hand = 1;
					res++;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}