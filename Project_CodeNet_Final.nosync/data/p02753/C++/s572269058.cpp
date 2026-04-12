#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,i,j,k,a=0,b=0;
	string s;
	cin>>s;
	for(i=0;i<3;i++)
	{
		if(s[i]=='A')a++;
		else b++;
	}
	if(a==3||b==3)
	{
		printf("No");
	}
	else printf("Yes");
}