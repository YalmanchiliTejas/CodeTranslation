#include<iostream>
#include<cstdio>
using namespace std;const int mod=1000000007;typedef pair<long long,long long> pii;int h[105];
inline int qpow(int a,int b) {int rtv=1;for (;b;b>>=1,a=1LL*a*a%mod) if (b&1) rtv=1LL*rtv*a%mod;return rtv;}
inline pii dac(int l,int r,int bnd) {long long mn=1e18,cnt=0,rem=r-l+1,ans0=1,ans1=1;pii _;
	for (int i=l;i<=r;++i) if (h[i]<mn) mn=h[i],cnt=1;else if (h[i]==mn) ++cnt;
	if (cnt==r-l+1) return make_pair((qpow(2,r-l+1)+mod-2)%mod,qpow(2,mn-bnd-1));
	for (int i=l,j=0;i<=r+1;++i) if (!j&&h[i]>mn) j=i;
		else if (j&&(h[i]==mn||i>r)) {rem-=i-j,_=dac(j,i-1,mn),j=0;
			ans0=1LL*ans0*(_.first+(4LL*_.second%mod)%mod)%mod,ans1=1LL*ans1*(_.second<<1)%mod;
		}ans0=(ans0-ans1+mod)%mod;
	return make_pair((1LL*ans0*qpow(2,rem)%mod+1LL*ans1*(qpow(2,rem)+mod-2)%mod)%mod,1LL*ans1*qpow(2,mn-bnd-1)%mod);
}int main() {int n,prod=1;pii _;scanf("%d",&n);for (int i=1;i<=n;++i) scanf("%d",h+i);
	if (n<2) return 0*printf("%d",qpow(2,h[1]));
	for (int i=1;i<=n;++i) if (h[i]>h[i-1]&&h[i]>h[i+1])
		prod=1LL*prod*qpow(2,h[i]-max(h[i-1],h[i+1]))%mod,h[i]=max(h[i-1],h[i+1]);
	_=dac(1,n,0);printf("%lld",1LL*prod*((_.first+_.second+_.second)%mod)%mod);return 0;
}