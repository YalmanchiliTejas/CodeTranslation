#include<bits/stdc++.h>
using namespace std;
int r,g,b;
int ans=0;
int main()
{
	cin>>r>>g>>b;
	ans=r*100+g*10+b;
	if(ans%4==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}