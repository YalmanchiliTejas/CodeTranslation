#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define EACH(t,i,c) for(t::iterator i=(c).begin(); i!=(c).end(); ++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);

typedef vector<pii> vp;


vp trail;

int r,c,m;
int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
bool dfs(int cx,int cy,int tx,int ty,vp &t,vs &field,vvi &visited){
	visited[cy][cx]=1;
	if(cx==tx&&cy==ty){
		REP(i,t.size()){
			trail.push_back(t[i]);
		}
		return true;
	}
	REP(i,4){
		int x=cx+dx[i],y=cy+dy[i];
		if(x<0||y<0||x>=c||y>=r||field[y][x]=='#'||visited[y][x]){
			continue;
		}
		vp nt(t);
		nt.push_back(make_pair(y,x));
		if(dfs(x,y,tx,ty,nt,field,visited))return true;
	}
	return false;
}

int main(){
	cin>>r>>c>>m;
	vs field(r);
	REP(i,r){
		cin>>field[i];
	}
	vvi con(r,vi(c));
	vvi on(r,vi(c));
	vvi off(r,vi(c));

	REP(i,r)REP(j,c){
		cin>>con[i][j];
	}
	REP(i,r)REP(j,c){
		cin>>on[i][j];
	}
	REP(i,r)REP(j,c){
		cin>>off[i][j];
	}

	vp tasks(m);
	REP(i,m){
		cin>>tasks[i].first>>tasks[i].second;
	}


	vvi last(r,vi(c,-1));
	int cost=0;
	int turn=0;
	FOR(i,1,m){
		vvi visited(r,vi(c));
		vp t;
		if(i==1){
			t.push_back(tasks[i-1]);
		}
		dfs(tasks[i-1].second,tasks[i-1].first,tasks[i].second,tasks[i].first,t,field,visited);
		REP(i,trail.size()){
			int y=trail[i].first,x=trail[i].second;
			if(last[y][x]==-1){
				cost+=on[y][x];
			}else if((turn-last[y][x])*con[y][x]<on[y][x]+off[y][x]){
				cost+=(turn-last[y][x])*con[y][x];
			}else{
				cost+=on[y][x]+off[y][x];
			}
			last[y][x]=turn;
			turn++;
		}
		trail.clear();
	}
	REP(y,r)REP(x,c){
		if(last[y][x]!=-1){
			cost+=off[y][x];
		}
	}
	cout<<cost<<endl;


}