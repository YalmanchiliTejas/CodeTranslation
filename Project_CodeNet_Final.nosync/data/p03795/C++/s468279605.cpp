#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,c;
	cin >> n;
	int a = n*800;
	int b = 0;
	while (n >= 15) {
		b = b+200;
		n = n-15;
	}
	c = a-b;
	cout << c;
}
