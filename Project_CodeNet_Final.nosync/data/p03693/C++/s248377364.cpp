#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	string digits = "";
	string temp = "";
	
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		digits += temp;
	}
	
	int num = atoi(digits.c_str());
	
	if (num % 4 == 0)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}