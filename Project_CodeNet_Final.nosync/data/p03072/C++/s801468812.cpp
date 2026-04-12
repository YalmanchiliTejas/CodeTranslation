#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	int h[25];
	int ans = 0;
	int c = 0;
	for (int i = 0; i < N; i++) {
		cin >> h[i];
		if (ans <= h[i]) {
			ans = h[i];
			c++;
		}
	}
	cout << c;
}