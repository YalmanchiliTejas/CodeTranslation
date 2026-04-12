#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <time.h>

using namespace std;
typedef long long int ll;

long long int powmod(long long int a, long long int k, long long int m){ //0<=a<=1e9, 0<k<=1e18, 0<m<=1e9
	if(a==0){
		return 0;
	}
	long long int apow[30], c[30];
	for(int i=0; i<30; i++){
		if(i==0){
			apow[i]=a;
			c[i]=1;
		}else{
			apow[i]=apow[i-1]*apow[i-1]%m;
			c[i]=c[i-1]*2;
		}
	}
	long long int ans=1;
	for(int i=29; i>=0; i--){
		if(k>=c[i]){
			ans=ans*apow[i]%m;
		}
		k=k%c[i];
	}
	return ans;
}
 
ll inv(ll x, ll p){
  return powmod(x, p-2, p);
}

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll p[3001], p2[3001];
	p[0]=1, p2[0]=2;
	for(ll i=1; i<=n; i++){
		p[i]=p[i-1]*2%m;
		p2[i]=p2[i-1]*p2[i-1]%m;
	}
	ll pk[3002][3002];
	for(ll i=1; i<=n+1; i++){
		pk[i][0]=1;
		for(ll j=1; j<=n; j++){
			pk[i][j]=pk[i][j-1]*i%m;
		}
	}
	ll f[3001], invf[3001];
	f[0]=1;
	for(ll i=1; i<=n; i++){
		f[i]=f[i-1]*i%m;
	}
	invf[n]=inv(f[n], m);
	for(ll i=n-1; i>=0; i--){
		invf[i]=invf[i+1]*(i+1)%m;
	}
	ll c[3001];
	c[0]=1;
	ll ans=p2[n];
	for(ll k=1; k<=n; k++){
		ll x=p[n-k];
		ll px[3001];
		px[0]=1;
		for(ll i=1; i<=k; i++){
			px[i]=px[i-1]*x%m;
		}
		ll s[3001];
		s[0]=1;
		for(ll i=1; i<=k; i++){
			if(i%2==0){
				s[i]=(s[i-1]+px[i]*invf[i]%m)%m;
			}else{
				s[i]=(s[i-1]-px[i]*invf[i]%m+m)%m;
			}
		}
		c[k]=0;
		for(ll i=0; i<=k; i++){
			c[k]=(c[k]+px[k-i]*invf[k-i]%m*s[i]%m*pk[k+1-i][k]%m)%m;
		}
		if(k%2==0){
			ans=(ans+f[n]*invf[n-k]%m*invf[k]%m*p2[n-k]%m*c[k]%m)%m;
		}else{
			ans=(ans+m-f[n]*invf[n-k]%m*invf[k]%m*p2[n-k]%m*c[k]%m)%m;
		}
	}
	printf("%lld\n", ans);
	return 0;
}