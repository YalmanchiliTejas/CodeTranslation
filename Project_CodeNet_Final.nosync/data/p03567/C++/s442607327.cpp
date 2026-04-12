#include<iostream>
#include<cstring>
using namespace std;
char s[100001];
int main()
{
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++)
		if(s[i]=='A'&&s[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	cout<<"No"<<endl;
}