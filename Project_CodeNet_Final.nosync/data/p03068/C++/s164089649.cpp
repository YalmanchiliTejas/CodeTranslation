#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	string a;
	cin>>a;
	cin>>k;
	k--;
	int x;
	for(x=0;x<a.size();x++)
	{
		if(a[x]!=a[k])
		{
			a[x]='*';
		}
		cout<<a[x];
	}
	cout<<endl;
	
}