#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string k = "No";
	for(int i = 0;i < s.length() - 1;i++)
	{
		if(s.substr(i,2) == "AC")
		{
			k = "Yes";
		}
	}
	cout << k <<endl;
	return 0;
}
