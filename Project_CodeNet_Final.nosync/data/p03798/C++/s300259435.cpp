#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[100000];
int n;
string s;
cin>>n>>s;
s=s+s;
for(int i=0;i<2;i++)
  for(int j=0;j<2;j++)
  {
  	a[0]=i;
  	a[1]=j;
  	for(int i=2;i<=n+1;i++)
  	{
  		if(a[i-1]&&s[i-1]=='o')a[i]=a[i-2];
  		if(!a[i-1]&&s[i-1]=='o')a[i]=1-a[i-2];
  		if(a[i-1]&&s[i-1]=='x')a[i]=1-a[i-2];
  		if(!a[i-1]&&s[i-1]=='x')a[i]=a[i-2];
	}
	if(a[0]==a[n]&&a[1]==a[n+1])
	{
		for(int i=0;i<n;i++)cout<<(a[i]?"S":"W");
		return 0;
	}
  }
  cout<<-1;
return 0;
}