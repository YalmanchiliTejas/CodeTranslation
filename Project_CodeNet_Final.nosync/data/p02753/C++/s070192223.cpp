#include <iostream>
#include <string>
using namespace std;

int main()
{

	string textS;

	cin >> textS;

	char startC = textS[0];
	bool flag = false;

	for (int i = 1; i < 3; i++)
	{
		if(textS[i] != startC){
			flag = true;
			break;
		}
	}
		
	cout << (flag ? "Yes" : "No") << endl;
	return 0;
}