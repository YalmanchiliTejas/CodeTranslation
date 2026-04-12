#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false);
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	fast_io;
	int x, n, h;
	int cont = 0;
	cin >> n;
	int max = 0;
	while (n--) {
		cin >> h;
		if(h >= max) {
			cont++;
			max = h;
		} 
	}
	cout << cont;
	return 0;	
}