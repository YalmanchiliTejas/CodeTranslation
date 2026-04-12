#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	vector<char> S = {};
	for (int i = 0; i < 3; i++)
	{
		char bufS;
		cin >> bufS;
		S.push_back(bufS);
	}
	char Z, O, T;
	Z = S[0];
	O = S[1];
	T = S[2];
	if (Z == O && O == T)
		cout << "No";
	else
		cout << "Yes";
	
	
	system("pause");
	return 0;
}