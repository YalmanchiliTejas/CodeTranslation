#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str; cin >> str;
	bool one = false, two = false;
	for(int i=0; i<str.size(); i++)
	{
		if(str[i] == 'A') one = true;
		if(str[i] == 'B') two = true;
	}
	if(one && two) cout << "Yes";
	else		   cout << "No";
	cout << '\n';
	return 0;
}