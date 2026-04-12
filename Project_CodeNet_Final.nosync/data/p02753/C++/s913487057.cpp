#include <iostream>
#include <string>
#include <vector>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s == "AAA" || s == "BBB")
		cout << "No";
	else
		cout << "Yes";
}