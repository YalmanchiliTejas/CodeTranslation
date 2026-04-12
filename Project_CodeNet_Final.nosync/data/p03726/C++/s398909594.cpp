#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	 char ch=nc(); int i=0,f=1;
	 while(!isdigit(ch)) {if(ch=='-')f=-1; ch=nc();}
	 while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	 return i*f;
}

const int N=1e5+50;
int n,rt=1,tag=0;
vector <int> edge[N];
inline int dfs(int x,int f) {
	if(tag) return 1;
	int cnt=0;
	for(auto v:edge[x]) 
		if(v^f) cnt+=dfs(v,x);
	if(!cnt) return 1;
	else if(cnt==1) return 0;
	else return tag=1;
}
int main() {
	n=rd();
	if(n==2) return puts("Second"),0;
	for(int i=1;i<n;i++) {
		int x=rd(), y=rd();
		edge[x].push_back(y);
		edge[y].push_back(x);
	} 
	while(edge[rt].size()<2) ++rt;
	cout<<((dfs(rt,0)||tag)?"First":"Second");
}