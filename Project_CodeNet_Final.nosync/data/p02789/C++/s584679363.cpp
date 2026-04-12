#include<bits/stdc++.h>
#define FOR(i,x) for(i=1;i<=x;i++)
using namespace std;
using ll = long long int;
typedef vector<ll> vi;
ll k,b,ar[11]={};
void Next_letter()
{
	char k;
	cin>>k,k++;
	cout<<k<<"\n";
}
void concat()
{
	string a,b;
	cin>>b>>a;
	cout<<a+b<<"\n";
}
void pass()
{
	cin>>k>>b;
	cout<<(k==b?"Yes":"No")<<"\n";
	return;
}
int main()
{
    pass();
    return 0;
}