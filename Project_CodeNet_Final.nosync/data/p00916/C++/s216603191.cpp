#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;i++)
#define ALL(s) s.begin(),s.end()
#define IN(l,x,r) (l)<=(x) && (x) < (r)
typedef long long ll;
typedef pair<ll ,ll> Q;

struct UnionFind{
  vector<int> par,rank,ss;int size;
  UnionFind(int n){
	REP(i,n) par.push_back(i);
	rank=vector<int>(n);ss=vector<int>(n,1);size=n;
  }
  int root(int x){
	if(par[x]==x)return x;
	return par[x]=root(par[x]);
  }
  bool same(int x,int y){
	return root(x)==root(y);
  }
  void unite(int x,int y){
	x=root(x);y=root(y);
	if(x==y)return;
	if(rank[x]<rank[y]){
	  par[x]=y;ss[y]+=ss[x];
	}else{
	  par[y]=x;ss[x]+=ss[y];
	}
	if(rank[x]==rank[y])rank[x]++;
	size--;
  }
  int getS(int x){
	return ss[root(x)];
  }
};

int Y,X;
int enc(int y,int x){
  return y*X+x;
}

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};



int main() {
  while (true) {
	int n;cin >>n;if(n==0)break;
	vector<int> xs,ys;

	vector<int> ls(n),ts(n),rs(n),bs(n);
	REP(i,n){
	  cin >> ls[i] >> ts[i] >> rs[i] >> bs[i];
	  ls[i]*=2;ts[i]*=2;rs[i]*=2;bs[i]*=2;
	  for(int d=-1;d<=1;d++){
		xs.push_back(ls[i]+d);ys.push_back(ts[i]+d);
		xs.push_back(rs[i]+d);ys.push_back(bs[i]+d);
	  }
	}
	sort(ALL(xs));xs.erase(unique(ALL(xs)),xs.end());
	sort(ALL(ys));ys.erase(unique(ALL(ys)),ys.end());

	X=xs.size();Y=ys.size();
	vector<vector<bool>> online(Y,vector<bool>(X));

	REP(yi,Y)REP(xi,X){
	  REP(i,n){
		if(xs[xi]==ls[i] && bs[i] <= ys[yi] && ys[yi] <=ts[i] )online[yi][xi]=true;
		if(xs[xi]==rs[i] && bs[i] <= ys[yi] && ys[yi] <=ts[i] )online[yi][xi]=true;
		if(ys[yi]==bs[i] && ls[i] <= xs[xi] && xs[xi] <=rs[i] )online[yi][xi]=true;
		if(ys[yi]==ts[i] && ls[i] <= xs[xi] && xs[xi] <=rs[i] )online[yi][xi]=true;
	  }
	}

	UnionFind uf(Y*X);
	REP(yi,Y)REP(xi,X)if(!online[yi][xi]){
	  REP(d,4){
		int nyi=yi+dy[d],nxi=xi+dx[d];
		if(IN(0,nyi,Y) && IN(0,nxi,X)){
		  if(!online[nyi][nxi]){
			uf.unite(enc(yi,xi),enc(nyi,nxi));
		  }
		}
	  }
	}
	int res=uf.size;
	REP(yi,Y)REP(xi,X)if(online[yi][xi])res--;
	cout << res <<endl;
  }
}