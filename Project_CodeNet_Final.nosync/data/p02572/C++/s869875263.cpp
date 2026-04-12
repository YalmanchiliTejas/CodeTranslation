#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define mod 1000000007
int main(){
	int n;
	cin>>n;
	long long int a[n],asum=0,sum=0;
	rep(i,n){
		cin>>a[i];
		asum=(asum+a[i])%mod;
	}
	rep(i,n-1){
		asum=(asum-a[i])%mod;
		sum=(sum+(a[i]*asum)%mod)%mod;
	}
	if(sum<0)sum+=mod;
	cout << sum;
		
	return 0;
}
