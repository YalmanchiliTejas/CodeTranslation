#include <iostream>
#include <string>

using namespace std;

int main() {
	const string a = "yuiophjklnm";
	string b;
	while (getline(cin, b)) {
		if (b.size() == 1 && b[0] == '#') {
			break;
		}
		int count = 0;
		int hantei;
		int mae;
		for (int i = 0; i < b.size(); i++) {
			if (i != 0) {
				mae = hantei;
			}
			hantei = 1;
			for (int j = 0; j < a.size(); j++) {
				if (b[i] == a[j]) {
					hantei = 0;
					break;
				}
			}
			if (i != 0) {
				if (hantei != mae) {
					count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}