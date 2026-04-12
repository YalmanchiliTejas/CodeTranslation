#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;
const ll MN = 10001000;
ll fp[MN],ip[MN],pt[MN];
ll mul(ll a, ll b) {return (a*b)%M;}
ll bp(ll b, ll p) {
	ll ac = 1;
	while(p) {
		if(p&1) {ac = mul(ac,b);}
		b = mul(b,b);
		p >>= 1;
	}
	return ac;
}
ll fac(ll p) {
	if(p <= 1) {return 1;}
	if(fp[p] != -1) return fp[p];
	if(p > 10000) {fac(p-10000);}
	return fp[p] = mul(p,fac(p-1));
}
ll inv(ll b) {
	return bp(b,M-2);
}
ll ifac(ll b) {
	if(b < MN) {
		if(ip[b] != -1) {return ip[b];}
		return ip[b] = inv(fac(b));
	}
	return inv(fac(b));
}
ll ch(ll n, ll k) {
	if(k > n || k < 0) return 0;
	return mul(mul(fac(n),ifac(k)),ifac(n-k));
}
int main() {
	memset(fp,-1,sizeof(fp));
	memset(ip,-1,sizeof(ip));
	ll n;
	cin >> n;
	pt[0] = 1;
	for(int i=0;i<n;i++) {
		//pt[i+1] = mul(2,pt[i]);
		pt[i+1] = 2*pt[i];
		if(pt[i+1] >= M) {pt[i+1] -= M;}
	}
	ll res = bp(3,n);
	ll tot = 0;
	for(int i=0;i<n/2;i++) {
		tot += mul(ch(n,i),pt[i]);
	}
	tot *= 2;
	res = (res-tot);
	res = ((res%M)+M)%M;
	cout << res << '\n';
}
