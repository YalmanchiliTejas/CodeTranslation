#include<iostream>
#include<string>
using namespace std;
int main()
{
	char ch;
	int n,i,k;
	string s;
	cin>>n>>s>>k;
	ch=s[k-1];
	for(i=0;i<n;i++)
	{
		if(ch==s[i])
		cout<<s[i];
		else
		cout<<"*";
	}
	cout<<endl;
	return 0;
}