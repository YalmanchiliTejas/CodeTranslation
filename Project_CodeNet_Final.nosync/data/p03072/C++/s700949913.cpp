#include <iostream>

using namespace std;

int main(void) {
	int N,a,b=1;
	cin >> N;
	int h[20];
	
	for (int i = 0; i < N; i++) {
		cin >> h[i];
	}

	a = h[0];

	for (int i = 1; i < N; i++) {
		
		if (h[i] >= a) {
			a = h[i];
			b++;
		}
	}
	cout << b;

	return 0;

	
}