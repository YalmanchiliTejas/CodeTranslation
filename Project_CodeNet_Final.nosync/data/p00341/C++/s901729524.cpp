#include <iostream>
using namespace std;

int cnt[101];

int main() {
	int i;
	for (i = 0; i < 12; i++) {
		int len;
		cin >> len;
		cnt[len]++;
	}
	for (i = 0; i < 101; i++) {
		if (cnt[i] % 4) {
			cout << "no" << endl;
			return 0;
		}
	}
	
	cout << "yes" << endl;
	return 0;
}