#include <iostream>
#include <string>
using namespace std;

string s, r = "yuiophjklnm";

int main(){
	while (cin >> s && s != "#") {
		bool t, f = true;
		int c = 0;
		for (int i = 0; i < s.size(); i++) {
			t = false;
			for (int j = 0; j < r.size(); j++) {
				if (s[i] == r[j]) {
					t = true;
					break;
				}
			}
			if (i == 0) {
				f = t;
			}
			else {
				if ((t || f) && (!t || !f)) {
					c++;
					f = !f;
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}