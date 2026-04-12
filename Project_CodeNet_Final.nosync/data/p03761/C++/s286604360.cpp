#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,a[114][514]={0};
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<s.size();j++)a[i][s[j]-97]++;
	}
	for(int j=0;j<26;j++)
	{
		a[n][j]=810;
		for(int i=0;i<n;i++)
		{
			a[n][j]=min(a[n][j],a[i][j]);
		}
		for(int i=0;i<a[n][j];i++)cout<<(char)(97+j);
	}
  	cout<<endl;
}