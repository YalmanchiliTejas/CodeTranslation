#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using namespace std;
using ll=long long;

const int inf =1 << 16;
const ll mod=1000000007LL;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

string field[55];
vector<int> cur;

int dist[55][55],prv[55][55][2];	


void bfs(int r,int c,int sr,int sc,int tr,int tc){
	rep(i,55)rep(j,55) dist[i][j]=inf,prv[i][j][0]=prv[i][j][1]=-1;
	queue<int> q;
	dist[sr][sc]=0,q.push(sr),q.push(sc);
	while(!q.empty()){
		int cr=q.front();q.pop();
		int cc=q.front();q.pop();
		rep(i,4){
			int nr=cr+dx[i],nc=cc+dy[i];
			if(nr<0||r<=nr||nc<0||c<=nc) continue;
			if(field[nr][nc]=='#' ) continue;
			if(chmin(dist[nr][nc],dist[cr][cc]+1)){
				q.push(nr),q.push(nc);
				prv[nr][nc][0]=cr;
				prv[nr][nc][1]=cc;
			}
		}
	}

	int cr=tr,cc=tc;
	vector<int> tmp;
	while(1){
		if(prv[cr][cc][0]==-1) break;
		tmp.push_back(cr*c+cc);
		int nr=prv[cr][cc][0];
		int nc=prv[cr][cc][1];
		swap(cr,nr),swap(cc,nc);
	}
	reverse(_all(tmp));
	copy(_all(tmp),back_inserter(cur));
	return;
}

ll per[55][55],on[55][55],off[55][55];
ll num[2510];

int main(void){
	int r,c,m;
	cin >> r >> c >> m;
	rep(i,r) cin >> field[i];
 	rep(i,r)rep(j,c) cin >> per[i][j];
	rep(i,r)rep(j,c) cin >> on[i][j];
	rep(i,r)rep(j,c) cin >> off[i][j];
	
	int pr=-1,pc=-1;
	rep(i,m){
		int cr,cc;
		cin >> cr >> cc;
		if(pr==-1&&pc==-1) 
			cur.push_back(cr*c+cc);
		else
			bfs(r,c,pr,pc,cr,cc);
		swap(cr,pr),swap(cc,pc);
	}

	int n=cur.size();
	vector<int> tmp(n,0);
	clr(num,-1);
	
	rrep(i,n){
		tmp[i]=num[cur[i]];
		num[cur[i]]=i;
	//	cerr << tmp[i] << " " << num[cur[i]] << endl;	
	}

	ll ans=0LL;
	rep(i,n){
		int cr=cur[i]/c,cc=cur[i]%c;
		// cerr << i << " " << cr << " " << cc << " " << tmp[i] << endl;
		if(tmp[i]!=-1)
			ans+=min(per[cr][cc]*(tmp[i]-i),on[cr][cc]+off[cr][cc]);
		else
			ans+=on[cr][cc]+off[cr][cc];
	}
	cout << ans << endl;
	return 0;
}