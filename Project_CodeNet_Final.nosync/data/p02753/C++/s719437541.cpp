#include <iostream>
using namespace std;

int main() {
	char a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;
	if (a == b && b == c) cout << "No";
	else cout << "Yes";
}