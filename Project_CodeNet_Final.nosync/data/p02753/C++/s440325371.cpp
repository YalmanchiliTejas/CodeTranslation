#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int A= 0, B =0 ;
	for(int i = 0; i < 3; i++)
	{
	 	if(s[i]=='A')
	 	{
	 		A++;
	 	}
	 	else
	 	{
	 		B++;
	 	}
	}
	if(A==3 || B == 3)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes";
	}
}