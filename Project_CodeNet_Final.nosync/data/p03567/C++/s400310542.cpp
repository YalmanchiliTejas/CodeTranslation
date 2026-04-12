#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
char s[10];
stack<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<=len;i++)
	{
		if(s[i]=='A')
		  q.push(s[i]);
		else
		if(s[i]=='C'&&s[i-1]=='A')
		{
			if(!q.empty())
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}