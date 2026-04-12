#include <iostream>
#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define mp make_pair
using namespace std;
int mod=1e9+7;
int add(int a,int b)
{
    return (a%mod+b%mod)%mod;
}
int mul(int a,int b)
{
    return (a%mod*b%mod)%mod;
}
int32_t main() {
	// your code goes here

	  //cout<<"Case #"<<x++<<":\n";
	 int n,m,i,j,k;
	cin>>n;
	vi a(n),pre(n);
	for(i=0;i<n;i++)
	cin>>a[i];
	 pre[n-1]=a[n-1];
	 for(i=n-2;i>=0;i--)
	 pre[i]=add(pre[i+1],a[i]);
	 int sum=0;
	 for(i=0;i<n-1;i++)
	 sum=add(sum,mul(a[i],pre[i+1]));
	cout<<sum<<"\n";
	
	return 0;
}
