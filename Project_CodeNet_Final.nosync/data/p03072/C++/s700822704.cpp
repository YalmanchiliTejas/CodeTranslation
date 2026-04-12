#include<iostream>
#include<string>
using namespace std;

int n,ans;
int a[105],mx;

int main()
{
	
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		if(mx<=a[i]) ans++;
		mx=max(mx,a[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}