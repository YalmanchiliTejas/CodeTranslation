#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long
#define N 100005
ll sum[N],st,n,m;
int cnt[N],now;
int main(){
	std::cin>>n>>st>>m;
	int lst=0;
	while(1){
		if(cnt[st]){lst=cnt[st]; break;}
		cnt[st]=++now,sum[now]=sum[now-1]+st,st=st*st%m;
	}
	if(now==n) return std::cout<<sum[now]<<'\n',0;
	n-=lst-1;
	std::cout<<(sum[now]-sum[lst-1])*(n/(now-lst+1ll))+sum[n%(now-lst+1)+lst-1]<<'\n';
	return 0;
}