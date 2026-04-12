#include <iostream>
#include <string>
using namespace std;

int main() {
	int x;
	cin >> x;
	string out = "NO";
	if (x == 3 || x == 5 || x == 7){out = "YES";}
	cout << out << endl;
	return 0;
}