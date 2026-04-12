#include <iostream>
#include <string>
using namespace std;

int main() {

	int a, b, c;
	string s;
	cin >> a >> b >> c;

	int num = a * 100 + b * 10 + c;

	s = num % 4 == 0 ? "YES" : "NO";

	cout << s << endl;
}
