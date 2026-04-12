#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	int h = 0;
	int num = 0;
	for (int i = 0; i < n; ++i) {
		int h_i;
		cin >> h_i;
		if (h_i >= h) {
			h = h_i;
			++num;
		}
	}
	cout << num << endl;
	return 0;
}