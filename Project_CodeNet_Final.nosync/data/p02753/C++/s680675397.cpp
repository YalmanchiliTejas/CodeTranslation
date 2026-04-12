#include<iostream>
using namespace std;
int main() {
	string a;
	int p(0);
	cin >> a;
	//cout << a[0] << a[1] << a[2];
	for (int i = 0; i < 3; ++i) {
		if (a[i] == 'A') {
			++p;
			//cout << "P" << endl;
		}
		
	}
	if (p == 1 || p == 2) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}