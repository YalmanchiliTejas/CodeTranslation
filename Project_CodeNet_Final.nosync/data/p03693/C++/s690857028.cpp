// RGB Cards

#include <iostream>

using namespace std;

int main(){
	int r, g, b;
	cin >> r >> g >> b;

	int rgb = 100*r + 10*g + b;

	if (rgb % 4)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}