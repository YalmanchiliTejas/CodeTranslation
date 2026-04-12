#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long k,a,b,flag=0;
	cin>>k>>a>>b;
	if(a>=k){cout<<"1"<<endl;return 0;}
	if(b>=a){cout<<"-1"<<endl;return 0;}
	if((k-a)%(a-b)>=1) flag=1;
    cout<<((k-a)/(a-b)+flag)*2+1<<endl;
	return 0;
}