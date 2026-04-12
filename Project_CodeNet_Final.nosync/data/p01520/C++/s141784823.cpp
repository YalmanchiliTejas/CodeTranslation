#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n,t,e;
	int kari;
	int tokei[100];
	int para = 0;
	cin >> n >> t >> e;
	for (int i = 0; i < n; i++) {
		cin >> kari;
		if (t / kari > 0) {
			tokei[i] = t % kari;
			tokei[i] = min(tokei[i], kari-tokei[i]);
		} else {
			tokei[i] = kari - t;
		}
		if (tokei[i] <= e) {
			para = i+1;
		}
	}
	if (para > 0) {
		cout << para << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}