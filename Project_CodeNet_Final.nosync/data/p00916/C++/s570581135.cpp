#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define all(c) (c).begin(),(c).end()
#define fs first
#define sc second
#define pb push_back
#define show(x) cout << #x << " " << x << endl
#define MX 300
typedef long long ll;
ll sum[MX][MX];
bool visited[MX][MX];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
	visited[x][y]=true;
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx&&nx<MX&0<=ny&&ny<MX&&!visited[nx][ny]&&sum[x][y]==sum[nx][ny]) dfs(nx,ny);
	}
}
int main(){
	while(true){
		int n,l[50],r[50],t[50],b[50];
		vector<int> hs,ws;
		cin>>n;
		if(n==0) break;
		rep(i,n){
			cin>>l[i]>>t[i]>>r[i]>>b[i];
			hs.pb(t[i]-1);
			hs.pb(t[i]);
			hs.pb(t[i]+1);
			hs.pb(b[i]-1);
			hs.pb(b[i]);
			hs.pb(b[i]+1);
			ws.pb(l[i]-1);
			ws.pb(l[i]);
			ws.pb(l[i]+1);
			ws.pb(r[i]-1);
			ws.pb(r[i]);
			ws.pb(r[i]+1);
		}
		sort(all(hs));
		sort(all(ws));
		hs.erase(unique(all(hs)),hs.end());
		ws.erase(unique(all(ws)),ws.end());
		rep(i,n){
			l[i]=lower_bound(all(ws),l[i])-ws.begin();
			r[i]=lower_bound(all(ws),r[i])-ws.begin();
			t[i]=lower_bound(all(hs),t[i])-hs.begin();
			b[i]=lower_bound(all(hs),b[i])-hs.begin();
		}
		rep(i,MX) rep(j,MX) sum[i][j]=0;
		ll p=1;
		rep(i,n){
			for(int x=l[i];x<r[i];x++) for(int y=b[i];y<t[i];y++) sum[x][y]+=p;
			p*=2;
		}
		rep(i,MX) rep(j,MX) visited[i][j]=false;
		int cnt=0;
		rep(i,MX) rep(j,MX){
			if(!visited[i][j]) cnt++,dfs(i,j);
		}
		cout<<cnt<<endl;
	}
}