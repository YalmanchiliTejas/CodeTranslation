#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long a,b,c;
	cin>>a>>b>>c;
	if(a>b&&b<=c) cout<<-1<<endl;
	else if(a<=b) cout<<1<<endl; 
	else cout<<(((a-b)/(b-c)+bool((a-b)%(b-c)))<<1|1)<<endl;
}