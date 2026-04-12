#include<bits/stdc++.h>
using namespace std; 
int main()
{
	string a;
	cin>>a;
	int b=0,c=0;
	for(int i=0;i<a.size();i++)
	if(a[i]=='A')
	b++;
	else
	c++;
	if(b==0 || c==0)
	cout<<"No";
	else
	cout<<"Yes";
	return 0;
 } 