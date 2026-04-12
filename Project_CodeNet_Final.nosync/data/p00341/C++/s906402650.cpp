#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int line[13];
	for (int i = 1; i <= 12; ++i) {
		cin >> line[i];
	}
	sort(line + 1, line + 13);
	bool hantei = true;
	for (int i = 1; i <= 11; i += 2) {
		if (line[i] != line[i + 1]) {
			hantei = false;
			break;
		}
	}
	if (hantei) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	return 0;
}