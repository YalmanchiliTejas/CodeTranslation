#include <iostream>
using namespace std;

int a, b, t, r;

int main(){
	while (cin >> a >> b && a|b != 0) {
		t = a + b;
		r = 0;
		for (int i = 1; i < 5; i++) {
			cin >> a >> b;
			if (t < a + b) {
				r = i;
				t = a + b;
			}
		}
		char c = 'A' + r;
		cout << c << " " << t << endl;
	}

	return 0;
}