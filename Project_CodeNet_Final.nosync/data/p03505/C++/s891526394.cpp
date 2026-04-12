#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,a,b,n,s,t;
	cin>>k>>a>>b;
	if(a>=k){cout<<"1"<<endl;return 0;}
	n=a-b;
	if(n<=0){
		cout<<"-1"<<endl;
		return 0;
	}
	s=k-a;
	if(s%n==0)t=s/n;
	else t=s/n+1;
	cout<<t*2+1<<endl;
	return 0;
}