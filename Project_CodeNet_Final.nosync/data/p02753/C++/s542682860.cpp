#include <iostream>
using namespace std;

int main()
{
	char s[3];
	while (cin>>s)
	{
		char s1,s2,s3;
		s1=s[0];
		s2=s[1];
		s3=s[2];
		
		if (s1==s2&&s2==s3)
		cout<<"No"<<"\n";
		else 
		cout<<"Yes"<<"\n";
	}
 } 