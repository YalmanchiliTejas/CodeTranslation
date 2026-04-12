#include<iostream>
#include<vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> h(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}

	int hl = h[0];
	int c = 1;

	for (int i = 1; i < n; i++) {
		if (h[i] >= hl) {
			c++;
			hl = h[i];
		}
	}

	cout << c;

}