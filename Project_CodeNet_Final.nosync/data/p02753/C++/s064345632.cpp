#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm> 
using namespace std;
int main()
{
	long long i,j;
	char s[100];
	cin>>s;
	for(i=0;i<strlen(s)-1;i++)
	{
		if(s[i]!=s[i+1])
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}