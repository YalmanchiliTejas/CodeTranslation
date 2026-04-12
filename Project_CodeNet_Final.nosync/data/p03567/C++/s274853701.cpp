#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	
	cin >> s;
	
	cout << ((int)s.find("AC") != -1 ? "Yes" : "No") << endl;
	
	return (0);
}