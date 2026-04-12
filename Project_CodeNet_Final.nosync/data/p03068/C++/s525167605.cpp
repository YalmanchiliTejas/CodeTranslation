#include<iostream>
using namespace std;
int main()
{
	int n,k;
	string a;
	cin>>n;
	cin>>a;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		if(a[k-1]==a[i])
		{
			cout<<a[i];
		}
		if(a[k-1]!=a[i])
		{
			cout<<'*';
		}
	}
	return 0;
}