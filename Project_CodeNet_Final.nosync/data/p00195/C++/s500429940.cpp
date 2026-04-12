#include <iostream>
using namespace std;

int main() {
	int a[5][2];
	while(cin >> a[0][0] >> a[0][1], a[0][0] || a[0][1]) {
		for(int i = 1; i < 5; i++) {
			cin >> a[i][0] >> a[i][1];
		}
		int indx, mx = 0;
		for(int i = 0; i < 5; i++) {
			if(mx < a[i][0] + a[i][1]) {
				mx = a[i][0] + a[i][1];
				indx = i;
			}
		}
		cout << (char)('A' + indx) << " " << mx << endl;
	}
}