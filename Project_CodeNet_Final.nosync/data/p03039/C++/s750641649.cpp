#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
typedef long long llong;
using namespace std;
const llong DIV = 1000000007;

llong mod_pow(llong m, llong n, llong mod =DIV) {
	if(n==0){return 1;}
	if (n == 1){return m;}

	llong ret = mod_pow(m, n/2, mod);
	ret = ret * ret % mod;
	
	if (n&1){ret = (ret*m)%mod;}

	return ret;
}

llong ncr(llong n,llong r, llong mod =DIV){
	r = min(r,n-r);
	llong ret = 1;
	for (int i = 1; i <= r; i++) {
		ret = ret * (n-i+1) % mod;
		ret = ret * mod_pow(i, mod-2) % mod;
	}
	return ret;
}

int main(){
  llong n,m,k;
  cin>>n>>m>>k;
  llong ans = 0;
  for(int d = 1;d<n;d++){
	  ans = (ans + d*(n-d)*m*m)%DIV;
  }
  for(int d = 1;d<m;d++){
	  ans = (ans + d*(m-d)*n*n)%DIV;
  }
  cout<<((ncr(n*m-2,k-2)*ans)%DIV)<<endl;
  return 0;
}