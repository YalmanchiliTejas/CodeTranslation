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
	int x,y;
	int id;
	node(int x,int y,int id):x(x),y(y),id(id){}
};
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
	bool operator < (const edge& x) const{
		return w<x.w;
	}
};
int n;
int p[maxn];
vector<node>s;
vector<edge>e;
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
	int len=e.size();
	int cnt=0;
	sort(e.begin(),e.end());
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
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		s.pb(node(x,y,i));
	}
	sort(s.begin(),s.end(),cmp1);
	int len=s.size()-1;
	for(int i=0;i<len;i++){
		int ww=min(abs(s[i+1].x-s[i].x),abs(s[i+1].y-s[i].y));
		e.pb(edge(s[i].id,s[i+1].id,ww));
	}
	sort(s.begin(),s.end(),cmp2);
	for(int i=0;i<len;i++){
		int ww=min(abs(s[i+1].x-s[i].x),abs(s[i+1].y-s[i].y));
		e.pb(edge(s[i].id,s[i+1].id,ww));
	}
	cout<<kruskal()<<endl;
	return 0;
}
