#include<bits/stdc++.h>
#include <iostream>
using namespace std;
# define p 1000000007
int main() {
	// your code goes here
	int n;
	cin>>n;
	long long a[n],sum=0,res=0;
	for(long long i=0;i<n;i++){
	cin>>a[i];
	sum+=a[i];
	}
	for(long long i=n-1;i>=0;i--)
	{
		sum-=a[i];
		res+=((sum%p)*a[i]);
      res%=p;
	}
	cout<<res;
	return 0;
}