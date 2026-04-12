#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s == "BBB") {
		cout << "No";
	}
	else if (s == "AAA") {
		cout << "No"; // 1が表示される
	}
	else {
		cout << "Yes";
	}
	
	return 0;
}