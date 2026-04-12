#include <iostream>
#include<string>
//#include<algorithm>
//#include<vector>
//#include<cmath>

using namespace std;

int main()
{
	string S;
	cin >> S;
	if (S[0] == S[1] && S[1] == S[2]) 
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
	cout << endl;
	return 0;
}
