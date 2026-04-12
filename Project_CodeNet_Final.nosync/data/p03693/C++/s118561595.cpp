#include<iostream>
#include<string>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int out = 100 * x + 10 * y + z;
	if (out % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
	return (0);
}