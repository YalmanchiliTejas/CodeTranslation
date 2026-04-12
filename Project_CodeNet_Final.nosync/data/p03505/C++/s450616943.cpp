#include<bits/stdc++.h>
using namespace std;
long long k,a,b;
int main()
{
	cin>>k>>a>>b;
	if(a>=k){cout<<1<<endl;return 0;} 
	if(b>=a){cout<<-1<<endl;return 0;}
	if((k-a)%(a-b)>=1)cout<<((k-a)/(a-b)+1)*2+1<<endl;
	else cout<<((k-a)/(a-b))*2+1<<endl;
	return 0;
 } 