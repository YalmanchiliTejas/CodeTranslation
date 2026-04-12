#include <bits/stdc++.h>
using namespace std;
int  a,b,c;
int main()
{
	cin>>a>>b>>c;
	if((a*100+b*10+c)%4==0)
	cout<<"YES";
	else
	cout<<"NO";
	cout<<endl;
	return 0;
}