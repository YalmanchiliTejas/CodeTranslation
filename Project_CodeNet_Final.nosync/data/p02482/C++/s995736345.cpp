#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 0, b = 0;
	string result = "a == b";
	
	cin >> a >> b;
	
	if (a < b) result = "a < b";
	else if (a > b) result = "a > b";
	cout << result << endl;
}