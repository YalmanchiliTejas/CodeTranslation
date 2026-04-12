#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int main(void) {
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB")
		cout << "No";
	else
		cout << "Yes";
	return 0;
}