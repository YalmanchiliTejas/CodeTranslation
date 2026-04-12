#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int calc(int n,int m){
	int ans = (m*(m*m - 1))/3;
	ans = (ans*n)%mod;
	ans = (ans*n)%mod;
	return ans;
}

int powmod(int base,int exponent)
{
    if(exponent<0) exponent+=mod-1;
    int ans=1;
    while(exponent){
        if(exponent&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        exponent/=2;
    }
    return ans;
}

int nCrModp(int n, int r, int p) 
{ 
    int ans =1;
    for(int i = n;i >= n-r+1;i--){
    	ans = (ans*i)%mod;
    }
    for(int i =2 ;i<= r;i++){
    	ans = (ans*powmod(i,mod-2))%mod;
    }
    return ans;
} 

signed main() {
	// your code goes here
	int n,m,k;
	cin>>n>>m>>k;
	int ans = (calc(n,m) + calc(m,n))%mod;
	ans = (ans*500000004LL)%mod;
	int f = nCrModp(n*m-2,k-2,mod);
	cout<<(ans*f)%mod<<endl;
	return 0;
}