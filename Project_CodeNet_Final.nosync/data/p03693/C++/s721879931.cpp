
#include<map>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	char c;
	for (int i = 0; i < 3; i++) {
		cin >> c;
		s += c;
	}
	if (stoi(s)%4 == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}



	return 0;
}
