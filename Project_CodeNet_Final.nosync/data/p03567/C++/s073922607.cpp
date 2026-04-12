#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[1000];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<n;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}