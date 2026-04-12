#include <iostream>
#include <string>
using namespace std;

string s, r = "yuiophjklnm";

int main(){
	while (cin >> s && s != "#") {
		char fg; 
		int c = 0;
		for (int i = 0; i < s.size(); i++) {
			fg &= 0x01;
			for (int j = 0; j < r.size(); j++) {
				if (s[i] == r[j]) {
					fg |= 0x02;
					break;
				}
			}
			if (i == 0) {
				fg = fg >> 1;
			}
			else {
				if (fg == 0x01 || fg == 0x02) {
					c++;
					fg = fg >> 1;
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}