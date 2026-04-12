#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
long long n, a[55], l, r, m;
int main(){
	scanf("%lld", &n);
	rep(i,n) scanf("%lld", a+i);
	auto J = [&]{
		for(long long s = m; s > max(-1LL,m-n); s--){
			long long cn = 0;
			rep(i,n) cn += max(0LL,(a[i] + 1 + s) / (n+1));
			if(cn <= s) return false;
		}
		return true;
	};
	for(l=-1,r=1e18;l+1<r;(J()?l:r)=m)m=(l+r)/2;
	printf("%lld\n", r);
}