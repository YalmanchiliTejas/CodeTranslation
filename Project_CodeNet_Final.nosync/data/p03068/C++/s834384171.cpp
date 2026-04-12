#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string a;
	int n,k;
	cin>>n>>a>>k;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=a[k-1])a[i]='*';
	}
	cout<<a;
	return 0;
} 