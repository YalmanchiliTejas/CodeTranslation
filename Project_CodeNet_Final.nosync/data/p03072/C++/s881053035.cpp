#include<iostream>
using namespace std;
int n,a[30],s,h=-999;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	h=a[0];
	s++;
	for(int i=1;i<n;i++)
	{
		if(h<=a[i])
		{
			h=a[i];
			s++;
		}
	}
	cout<<s<<endl;
}