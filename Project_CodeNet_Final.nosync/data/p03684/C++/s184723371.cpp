#include<bits/stdc++.h>
#define maxn 100050
#define inf 0x3f3f3f3f
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mm(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
const LL mod=1e9+7;
const LL INF=(LL)1e18;
using namespace std;
struct node{
	int x,y,id;
	node(){}
	node(int x,int y,int id):x(x),y(y),id(id){}
}s[maxn];
struct edge{
	int u,v,w;
	edge(){}
	edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator < (const edge& x) const{
		return w<x.w;
	}
}e[maxn<<1];
int n,len;
int p[maxn];
int cmp1(node a,node b){
	return a.x<b.x;
}
int cmp2(node a,node b){
	return a.y<b.y;
}
int find(int x){
	return x==p[x]?x:p[x]=find(p[x]);
}
int kruskal(){
	int ans=0;
	int cnt=0;
	sort(e,e+len);
	for(int i=0;i<=n;i++) p[i]=i;
	for(int i=0;i<len;i++){
		int x=find(e[i].u),y=find(e[i].v);
		if(x!=y){
			ans+=e[i].w;
			p[x]=y;
			cnt++;
		}
		if(cnt==n-1) break;
	}
	return ans;
}
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("ouput.txt","w",sdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		s[i]=node(x,y,i+1);
	}
	sort(s,s+n,cmp1);
	len=0;
	for(int i=0;i<n-1;i++){
		int ww=min(abs(s[i+1].x-s[i].x),abs(s[i+1].y-s[i].y));
		e[len++]=edge(s[i].id,s[i+1].id,ww);
	}
	sort(s,s+n,cmp2);
	for(int i=0;i<n-1;i++){
		int ww=min(abs(s[i+1].x-s[i].x),abs(s[i+1].y-s[i].y));
		e[len++]=edge(s[i].id,s[i+1].id,ww);
	}
	cout<<kruskal()<<endl;
	return 0;
}