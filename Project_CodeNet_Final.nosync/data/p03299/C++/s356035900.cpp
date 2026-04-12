#include <bits/stdc++.h>
using namespace std;
const int Maxn=105,mod=1e9+7;
int h[Maxn];
int ksm(int x,int k){
	int ret=1,tmp=x;
	while(k){
		if(k&1)ret=1ll*ret*tmp%mod;
		tmp=1ll*tmp*tmp%mod;k>>=1;
	}
	return ret;
}
pair<int,int>solve(int l,int r,int lim){
	int Min=*min_element(h+l,h+r+1);
	int cnt=count(h+l,h+r+1,Min);
	pair<int,int>ans=make_pair(1,1);
	if(cnt==r-l+1){
		ans.first=ksm(2,Min-lim);
		ans.second=(ans.first+ksm(2,cnt)-2)%mod;
		return ans;
	}
	vector<pair<int,int>>vec;
	for(int i=l;i<=r;i++){
		if(h[i]==Min)continue;
		int L=i;
		while(i<=r&&h[i]>Min)i++;
		vec.emplace_back(solve(L,i-1,Min));
	}
	int f=1,g=1;
	for(auto&i:vec){
		f=1ll*f*i.first%mod;
		g=1ll*g*(i.first+i.second)%mod;
	}
	ans.second=(1ll*(g-1ll*ksm(2,vec.size())*f)%mod*ksm(2,cnt)+1ll*f*(ksm(2,vec.size()+cnt)-2))%mod;
	ans.first=1ll*f*ksm(2,Min-lim)%mod;
	ans.second=(ans.second+ans.first)%mod;
	return ans;
}
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	cout<<(solve(1,n,0).second+mod)%mod<<"\n";
	return 0;
}