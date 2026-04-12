#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
int main(void) {
	
	int n;
	int h[100];
	int i;
	
	int a=1;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> h[i];
	}
	int max = h[0];

	for (i = 1; i < n; i++) {
		if (max <= h[i]) {
			max = h[i];
			a++;
		}
			
	}

	cout << a;
	return 0;
}