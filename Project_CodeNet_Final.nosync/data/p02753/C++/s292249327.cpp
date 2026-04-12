#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int flag1 = 0, flag2 = 0;
	for(int i = 0; i < str.size(); i ++)
	{
		if(str[i] == 'A') flag1 = 1;
		if(str[i] == 'B') flag2 = 1;
	}
	if(flag1 && flag2) cout << "Yes" <<'\n';
	else cout << "No" << '\n';
	return 0;
 } 