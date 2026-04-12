#include <iostream>
#include <string>

using namespace std;

string S;

int main(void)
{
	cin >> S;
	if(S.find("AC") != -1) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}