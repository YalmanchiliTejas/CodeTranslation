#include<bits/stdc++.h>
using namespace std;

int main() {
	int r, g, b;
	int rgb = 0;
	
	cin >> r >> g >> b;

	rgb = r * 100 + g * 10 + b;

	if (rgb % 4)cout << "NO";
	else cout << "YES";

}