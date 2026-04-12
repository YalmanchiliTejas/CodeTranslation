#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <climits>
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define RFOR(i,a,b) for (int i=(a)-1;i>=(b);i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int INF = 1e9;
const int MOD = 1e9 + 7;

using namespace std;


struct UnionFind{
	int par[100003];
	int rank[100003];
	UnionFind(int n){
		init(n);
	}
	void init(int n){		REP(i,n){par[i] = i;rank[i] = 0;}}
	int find(int a){
		if(par[a] == a)return a;
		return par[a] = find(par[a]);
	}
	void unite(int x,int y){
		x = find(x);
		y = find(y);
		if(x==y)return;
		if(rank[x]<rank[y])par[x] = y;
		else {
			par[y] = x;
			if(rank[x]==rank[y])rank[x]++;
		}
	}
	bool same(int x,int y){return find(x)==find(y);}
};

struct City{
    int x,y,num,num2;
};

bool xfirst(City& a,City& b){
    return a.x < b.x;
}
bool yfirst(City& a,City& b){
    return a.y < b.y;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;cin>>n;
  vector<City> xf(n),yf(n);
  REP(i,n){
      int x,y;cin>>x>>y;
      xf[i].x = yf[i].x = x;
      xf[i].y = yf[i].y = y;
      xf[i].num = yf[i].num = i+1;
  }
  sort(xf.begin(),xf.end(),xfirst);
  sort(yf.begin(),yf.end(),yfirst);
  vector<City> xf2(n-1),yf2(n-1);
  REP(i,n-1){
      xf2[i].x = xf[i+1].x - xf[i].x;
      yf2[i].y = yf[i+1].y - yf[i].y;
      xf2[i].num = xf[i].num;
      xf2[i].num2 = xf[i+1].num;
      yf2[i].num = yf[i].num;
      yf2[i].num2 = yf[i+1].num;
  }

  sort(xf2.begin(),xf2.end(),xfirst);
  sort(yf2.begin(),yf2.end(),yfirst);
  int ct = 1;
  long long ans = 0;
  UnionFind uni(n);
  int xi = 0,yi = 0;
  int xcost = xf2[0].x,ycost = yf2[0].y;
  bool Xturn = xcost <= ycost;

  while(ct < n){
      if(Xturn){
          if(xf2[xi].x == xcost){
              if(!uni.same(xf2[xi].num,xf2[xi].num2)){
                  uni.unite(xf2[xi].num,xf2[xi].num2);
                  ct++;
                  ans+=xcost;
              }
              xi++;
          }else{
              xcost = xf2[xi].x;
              if(ycost < xcost) Xturn = false;
          }
      }else{
          if(yf2[yi].y == ycost){
              if(!uni.same(yf2[yi].num,yf2[yi].num2)){
                  uni.unite(yf2[yi].num,yf2[yi].num2);
                  ct++;
                  ans+=ycost;
              }
              yi++;
          }else{
              ycost = yf2[yi].y;
              if(xcost <= ycost) Xturn = true;
          }
      }
  }
  cout << ans << endl;
  return 0;
}
