#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	int k;
	cin>>s;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[k-1])
		{
			cout<<s[i];
		}
		else
		{
			cout<<'*';
		}
	}
	return 0;
}