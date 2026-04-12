#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <functional>
#include <bitset>
#define DB cerr<<"D"<<endl
#define pb push_back
using namespace std; using ll=long long; using ld=long double; const int INF=1e9; const ll LINF=1e18; const double dINF = 1e18; const ld ldINF = 1e18; const double EPS = 1e-6;
template<typename T, typename U, typename O> void caut(T a, U b, O c){cout<<"("<<a<<","<<b<<","<<c<<") ";}
template<typename T, typename U> void caut(T a, U b){cout<<"("<<a<<","<<b<<") ";}
template<typename T> void caut(T a){cout<<"("<<a<<") ";}
using P=pair<double,int>;
const ll M = 1e9+7;

int main() {
  int h,w; cin>>h>>w;
  string s[h];
  for(int i=0;i<h;i++) cin>>s[i];
  
  queue<P> que; que.push({0,0});
  bool u[h][w]; fill(u[0],u[h],false); u[0][0]=true;

  while(!que.empty()) {
    P o = que.front(); que.pop();
    int x = o.first, y = o.second;
    if (x != h-1 && s[x+1][y] == '#' && !u[x+1][y]) {
      u[x+1][y]=true; que.push({x+1,y});
    }
    if (y != w-1 && s[x][y+1] == '#' && !u[x][y+1]) {
      u[x][y+1]=true; que.push({x,y+1});
    }
  }

  int ct = 0;
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if (s[i][j]=='#') ct++;
    }
  }
  if (ct != h+w-1) u[h-1][w-1]=false;

  if (u[h-1][w-1]) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}
// Thank you for making problems and running the contest