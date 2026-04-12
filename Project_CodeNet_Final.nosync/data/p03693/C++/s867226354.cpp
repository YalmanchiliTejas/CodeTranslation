#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,s=0;
	for(i=0;i<3;i++)
	{
		cin>>n;
		s+=n;
		if(i!=2)
			s*=10;
	}
	if(s%4==0)
		cout<<"YES";
	else 
		cout<<"NO";
	return 0;
}
