#include<iostream>
#include<cstdio>
#include<cstring>
const int N=1e5+2;
int n,dp[N],fir[N];
/*
dp state:
3:leaf
2:the subtree must be filled step by step from one player to another
1:all the subtree is 2
didn't set an unbreakable state?
*/
/*
dp state.v2:
1: leaf/all the subtree is 2;
2:the subtree must be filled step by step from one player to another
*/
struct edge{
	int to,nx;
}eg[N<<1];

inline void add(int a,int b){
	static int cnt;
	eg[++cnt]=(edge){b,fir[a]};
	fir[a]=cnt;
	eg[++cnt]=(edge){a,fir[b]};
	fir[b]=cnt;
}

inline int nxi(){
	int x=0;
	char c;
	while((c=getchar())>'9'||c<'0');
	while(x=x*10-48+c,(c=getchar())>='0'&&c<='9');
	return x;
}

bool dfs(int x,int fa){
/*	if(!fir[x]){
		dp[x]=3;
		return;
	}
	int cnt[4]={0};
	for(int i=fir[x];i;i=eg[i].nx){
		int y=eg[i].to;
		if(y!=fa){
			if(dfs(y,x)) return 1;
			++cnt[dp[y]];
			if(cnt[3]>1) return 1;
		}
	}
	if(cnt[1]+cnt[3]>1) return 1;
	if(!cnt[1]&&!cnt[3]){
		if(!fa) return 1;
		dp[x]=1;
	}
	else dp[x]=2;
	return 0;*/
	if(!fir[x]){
		dp[x]=1;
		return 0;
	}
	int cnt=0;
	for(int i=fir[x];i;i=eg[i].nx){
		int y=eg[i].to;
		if(y!=fa){
			if(dfs(y,x)) return 1;
			if(dp[y]==1){
				if(++cnt==2) return 1;
			}
		}
	}
	if(cnt) dp[x]=2;
	else{
		if(!fa) return 1;
		dp[x]=1;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
//	freopen("a.in","r",stdin);
#endif
	n=nxi();
	for(int i=1;i<n;++i){
		add(nxi(),nxi());
	}
	puts(dfs(1,0)?"First":"Second");
	return 0;
}