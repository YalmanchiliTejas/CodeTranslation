#include<cstring>
#include<iostream>
using namespace std;
int n,l,a[26],x[26];
string s;
char c;
int main()
{
	memset(x,1919810,sizeof(x));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		l=s.length();
		memset(a,0,sizeof(a));
		for(int k=0;k<l;k++)
		{
			a[s[k]-'a']++;
		}
		for(int k=0;k<26;k++)
		{
			x[k]=min(x[k],a[k]);
		}
	}
	int k=0;
	while(k<26)
	{
		c='a'+k;
		while(x[k]>0)
		{
			x[k]--;
			cout<<c;
		}
		k++;
	}
	cout<<endl;
}