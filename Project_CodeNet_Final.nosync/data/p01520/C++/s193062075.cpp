#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)

int main() {
	int N, T, E;
	cin >> N >> T >> E;
	
	for_(i,0,N) {
		int x;
		cin >> x;
		int X = x;
		
		while (X <= T + E) {
			if (T - E <= X && X <= T + E) {
				cout << i + 1 << endl;
				return 0;
			}
			
			X += x;
		}
	}
	
	cout << -1 << endl;
}