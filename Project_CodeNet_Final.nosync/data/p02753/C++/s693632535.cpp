#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	char n;
	int a=0,b=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='A')
		a++;
		else
		b++;
		
	}
	if(a==3||b==3)
	printf("No");
	else 
	printf("Yes");
} 