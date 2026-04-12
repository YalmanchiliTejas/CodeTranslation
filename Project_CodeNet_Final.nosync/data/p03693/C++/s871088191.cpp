#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(void) {

	int r, g, b;
	cin >> r >> g >> b;

	if ((100 * r + 10 * g + b) % 4 == 0)cout << "YES\n";
	else cout << "NO\n";

	return 0;
}