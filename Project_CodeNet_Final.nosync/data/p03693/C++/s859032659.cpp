#include<bits/stdc++.h>
using namespace std;
int a,b,c,t=0; 
int main()
{
	cin>>a>>b>>c;
	t=a*100+b*10+c;
	if(t%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
