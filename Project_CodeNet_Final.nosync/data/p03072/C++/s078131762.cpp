#include <bits/stdc++.h>
using namespace std; 

int main() {

	int maxSoFar = 0; 

	int n; 
	cin >> n; 
	int h[n]; 

	for(int i = 0; i < n; i++) {
		int height; 
		cin >> height; 
		if(height >= maxSoFar) {
			h[i] = 1; 
			maxSoFar = height; 
		}
		else {
			h[i] = 0; 
		}
	}

	int m = 0;

	for(int i = 0; i < n; i++) {
		m += h[i]; 
	} 

	cout << m << endl; 

	return 0; 
}