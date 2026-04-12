#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
bool flag=false;
int main()
{
	cin>>s;
	int len=s.length();
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='A'&&s[i+1]=='C')
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}