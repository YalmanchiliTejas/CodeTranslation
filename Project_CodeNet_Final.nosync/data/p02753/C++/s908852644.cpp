#include <iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
  
	string str;
	cin >> str;
	for (int i = 0; i < str.length() - 1; i++) {
		if (str[i] != str[i + 1]) {
			cout << "Yes";
			return 0;
		}

	}

	cout << "No";
	return 0;




}

