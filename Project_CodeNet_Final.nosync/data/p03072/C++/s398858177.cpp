#include<iostream>
using namespace std;
int main() {
	
	int n;
	cin >> n;
	int i;
	int h[20];
	for (i = 0; i < n; i++) {
		cin >> h[i];
	}
	int maxh = 0;
	int hcounter = 0;
	maxh = h[0];
	hcounter++;
	for (i = 1; i < n; i++) {
		if (h[i] >= maxh) {
			maxh = h[i];
			hcounter++;
		}
	}
	cout << hcounter << endl;
	return 0;
	
	
	//A
	/*
	int a,b;
	cin >> a >> b;
	int x = 0;
	for (int i = 0; i < 2; i++) {
		if (a > b) {
			x = x + a;
			a--;
		}
		else {
			x = x + b;
			b--;
		}
	}
	cout << x << endl;
	return 0;
	*/


}