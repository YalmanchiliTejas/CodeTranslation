#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <complex>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <functional>
#include <iterator>

using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define foreach(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define all(c) begin(c),end(c)
#define mp make_pair

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int INFTY=1<<29;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

int main()
{
	for(int h,w,m;cin>>h>>w>>m && h|w|m;){
		vs grid(h);
		rep(i,h) cin>>grid[i];
		vvi con(h,vi(w)),on=con,off=con;
		rep(i,h) rep(j,w) cin>>con[i][j];
		rep(i,h) rep(j,w) cin>>on[i][j];
		rep(i,h) rep(j,w) cin>>off[i][j];
		
		vector<pii> order(m);
		for(pii& p:order) cin>>p.first>>p.second;
		
		vector<pii> path(1,order[0]);
		rep(o,m-1){
			vector<vector<pii>> prev(h,vector<pii>(w,mp(-1,-1)));
			prev[order[o].first][order[o].second];
			queue<pii> q; q.push(order[o]);
			while(q.size()){
				int ci,cj; tie(ci,cj)=q.front(); q.pop();
				rep(k,4){
					int ni=ci+"\xff\x1\0\0"[k],nj=cj+"\0\0\xff\x1"[k];
					if(ni<0 || h<=ni || nj<0 || w<=nj
					|| grid[ni][nj]=='#' || prev[ni][nj]!=mp(-1,-1))
						continue;
					prev[ni][nj]=mp(ci,cj);
					q.emplace(ni,nj);
				}
			}
			vector<pii> temp;
			for(pii p=order[o+1];p!=order[o];p=prev[p.first][p.second])
				temp.push_back(p);
			reverse(all(temp));
			path.insert(end(path),all(temp));
		}
		
		vvvi time(h,vvi(w));
		rep(i,path.size()) time[path[i].first][path[i].second].push_back(i);
		
		int res=0;
		rep(i,h) rep(j,w) if(time[i][j].size()){
			int tmp=on[i][j];
			rep(k,time[i][j].size()-1){
				int t1=time[i][j][k],t2=time[i][j][k+1];
				tmp+=min(off[i][j]+on[i][j],con[i][j]*(t2-t1));
			}
			tmp+=off[i][j];
			res+=tmp;
		}
		cout<<res<<endl;
	}
}