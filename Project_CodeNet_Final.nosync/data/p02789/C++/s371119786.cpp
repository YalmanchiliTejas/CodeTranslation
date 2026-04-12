#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define endl "\n"
 
 
int pow1(int n, int p)
{
	if(p==0)	return 1;
	int x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}
 
int32_t main()
{
	fast;

	int n, m;
	cin>>n>>m;
	if(n==m)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}