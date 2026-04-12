#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;

//common
typedef int  i32;
typedef long long i64,ll;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#undef NDEBUG
//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T mod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}

int  dx[4]={1,0,-1,0};
int  dy[4]={0,1,0,-1};

class Main{
public:
	vector<vector<bool>> passed;
	int dfs(int y,int x,int ty,int tx,int t){
		if(y==ty && x==tx)return t;

		if(!IN(0,y,R) || !IN(0,x,C))return -1;
		if(passed[y][x])return -1;
		if(map[y][x]=='#')return -1;
		
		passed[y][x]=true;
		REP(di,4){
			int nx=x+dx[di],ny=y+dy[di];
			int goal=dfs(ny,nx,ty,tx,t+1);	
			if(goal!=-1){
				passT[ny][nx].push_back(t+1);
				return goal;
			}
		}
		return -1;
	}

	int R,C,M;
	vector<vector<vector<int>>> passT;
	vector<string> map;
		
	void run(){
		cin >> R >> C >> M;
		 map=vector<string>(R);
		REP(y,R)cin >> map[y];
		vector<vector<int>> perC(R,vector<int>(C)),onC(R,vector<int>(C)),offC(R,vector<int>(C));
		REP(y,R)REP(x,C) cin >> perC[y][x];
		REP(y,R)REP(x,C) cin >> onC[y][x];
		REP(y,R)REP(x,C) cin >> offC[y][x];
		vector<int> xs(M),ys(M);
		REP(i,M)cin >> ys[i] >> xs[i];

		passT=vector<vector<vector<int>>> (R,vector<vector<int>>(C));
		passT[ys[0]][xs[0]].push_back(0);
		int t=0;
		for(int i=0;i+1<M;i++){
			passed=vector<vector<bool>>(R,vector<bool>(C));
			t=dfs(ys[i],xs[i],ys[i+1],xs[i+1],t);
		}
		ll res=0;
		REP(y,R)REP(x,C){
			if(passT[y][x].size()>0){
				//first
				res+=onC[y][x];
				//mid
				for(int i=1;i<passT[y][x].size();i++){
					res+=min(perC[y][x]*(passT[y][x][i]-passT[y][x][i-1]),offC[y][x]+onC[y][x]);
				}
				//last
				res+=offC[y][x];
			}
		}
		cout <<res <<endl;
	}
};

 int main(){
	//ios::sync_with_stdio(false);
 	Main().run();
 	return 0;
 }