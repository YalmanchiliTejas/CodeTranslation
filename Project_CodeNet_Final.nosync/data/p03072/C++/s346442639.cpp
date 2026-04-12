#include<bits/stdc++.h>
using namespace std;
int n,st[22],top,x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>=st[top])
		 st[++top]=x;
	}
	cout<<top<<endl;
	return 0;
}