#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num[54],n,k,cnt[54];
ll dfs(ll x,ll y){
	if (y>=num[x]-1) return cnt[x];
	if (x==0) return 1;
	ll res=0;
	ll go=min(y-1,num[x-1]);
	if (y>1) res+=dfs(x-1,go);
	if (y>num[x]/2) res++;
	go=min(y-num[x]/2-1,num[x-1]);
	if (y>num[x]/2+1) res+=dfs(x-1,go);
	return res;
}
int main(){
	num[0]=1;
	cnt[0]=1;
	for (ll i=1;i<=50;i++){
		num[i]=num[i-1]*2+3;
		cnt[i]=cnt[i-1]*2+1;
	}
	cin>>n>>k;
	cout<<dfs(n,k);
}