#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main()
{
	cin>>a>>b>>c;
	d=a*100+b*10+c;
	if(d%4==0)  cout<<"YES";
	else    cout<<"NO";

	return 0;
}