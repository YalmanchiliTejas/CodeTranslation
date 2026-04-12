#include <iostream>
#include <string>
using namespace std;

int main() {
	int a[40] = {}, p, s, ju = 1, aaa;
	char knm;
	while (cin >> p >> knm >> s) {
		if (p == 0) { break; }
		a[p] = s;
	}
	for (int i = 30; i > -1; i--) {
		aaa = 0;
		for (int j = 0; j < 40;j++){
			if(a[j] == i){
				a[j] = (-1) * ju;
				aaa++;
			}
		}
		if (aaa > 0) { ju++; }
	}
	while (cin >> p){
		cout << a[p] * (-1) << endl;
	}
	return 0;
}