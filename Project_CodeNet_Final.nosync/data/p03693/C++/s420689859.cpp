#include <iostream>
#include<string>
#include<cctype>
using namespace std;

int main() {
	int r, b, g,an;
	cin >> r >> b >> g;
	an = 100 * r + 10 * b + g;
	if ((an % 4) == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}