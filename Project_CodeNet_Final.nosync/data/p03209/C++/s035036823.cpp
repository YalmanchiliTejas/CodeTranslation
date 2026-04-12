#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL f[55],g[55];
map<int,int> mp;

LL solve(LL n,LL l,LL r,LL ql,LL qr) {
	if (ql<=l && r<=qr) return g[n];
	if (n==1) {
		LL res=0; mp.clear();
		for (LL x=l+1;x<=r-1;x++) mp[x]=1;
		for (LL x=l;x<=qr;x++) res+=mp[x];
		return res;
	}
	LL mid=l+r>>1;
	LL res=0;
	if (ql<=mid-1) res+=solve(n-1,l+1,mid-1,ql,qr);
	if (qr>=mid+1) res+=solve(n-1,mid+1,r-1,ql,qr);
	if (ql<=mid && mid<=qr) res++;
	return res;
}

int main()
{
	cin>>n>>m;
	f[0]=g[0]=1; 
	for (int i=1;i<=n;i++) {
		f[i]=f[i-1]*2+3;
		g[i]=g[i-1]*2+1;
	}
	
	cout<<solve(n,1,f[n],1,m);	
	return 0;
} 