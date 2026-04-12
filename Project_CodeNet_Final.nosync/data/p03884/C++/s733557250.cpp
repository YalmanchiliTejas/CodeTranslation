#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(x, a, b) for(int x=a; x<=b; x++)
#define drp(x, a, b) for(int x=a; x>=b; x--)
typedef long long ll;
int u;
ll K, c[1000], v[1000];
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
ll C(int n, int m){
	ll res=1;
	int d=1;
	rep(i, 1, m) d*=i;
	rep(i, n-m+1, n) res*=i/gcd(i, d), d/=gcd(i, d);
	return res;
}
int D=7;
int main(){
	cin>>K;
	u=600;
	rep(i, D, 600)
	{
		c[i]=C(i, D);
		if(c[i]>K){ u=i-1; break; }
	}
	drp(i, u, D)
	{
		while(K>=c[i]) v[i]++, K-=c[i];
	}
	rep(i, D, u)
	{
		printf("FESTIVA");
		rep(j, 1, v[i]) putchar('L');
	}
}