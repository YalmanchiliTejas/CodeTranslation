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
#include <memory>
#include <time.h>
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
#define EXIST2(s,e) (find(ALL(s),(e))!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);


typedef vector<ll> vl;
typedef vector<vl> vvl;

int get_index(vi &vec,int item){
	int ret=find(ALL(vec),item)-vec.begin();
	return ret;
}

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void fill(vvl &f,ll id,int y,int x,vvi &visited,int h,int w){
	visited[y][x]=1;
	REP(d,4){
		int yy=y+dy[d];
		int xx=x+dx[d];
		if(yy>=0&&xx>=0&&yy<h&&xx<w&&!visited[yy][xx]&&f[yy][xx]==id){
			fill(f,id,yy,xx,visited,h,w);
		}
	}
}

int main(){
	int n;
	while(cin>>n,n){
		vi l(n),t(n),r(n),b(n);
		vi xs,ys;
		REP(i,n){
			cin>>l[i]>>t[i]>>r[i]>>b[i];
			swap(t[i],b[i]);
			xs.push_back(l[i]);
			xs.push_back(r[i]);
			ys.push_back(t[i]);
			ys.push_back(b[i]);
		}
		sort(ALL(xs));
		sort(ALL(ys));
		xs.erase(unique(ALL(xs)),xs.end());
		ys.erase(unique(ALL(ys)),ys.end());
		int h=(ys.size()+2)*2,w=(xs.size()+2)*2;
		vvl f(h,vl(w));
		REP(i,n){
			FOR(y,(get_index(ys,t[i])+1)*2+1,(get_index(ys,b[i])+1)*2+1){
				FOR(x,(get_index(xs,l[i])+1)*2+1,(get_index(xs,r[i])+1)*2+1){
					f[y][x]|=(1LL<<i);
				}
			}
		}
		int ans=0;
		vvi visited(h,vi(w));
		REP(i,h){
			REP(j,w){
				if(!visited[i][j]){
					ans++;
					fill(f,f[i][j],i,j,visited,h,w);
				}
			}
		}
		cout<<ans<<endl;
	}
}