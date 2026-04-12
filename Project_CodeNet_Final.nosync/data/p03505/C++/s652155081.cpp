#include<bits/stdc++.h>

using namespace std;
long long int k,a,b;
int main()
{
	cin>>k>>a>>b;
	if(a<=b&&a<k)cout<<-1;
	else if(k<=a)cout<<1;
	else cout<<(k-a-1)/(a-b)*2+3;
	cout<<"\n";
    
    return 0;
}