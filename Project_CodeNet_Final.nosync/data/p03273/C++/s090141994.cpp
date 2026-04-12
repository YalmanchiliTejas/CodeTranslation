#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <functional>
#include <stack>
#include <iomanip>
#include <limits>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
using Graph=vector<vector<int>>;
using edge= struct{int to;ll cost;};
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
typedef priority_queue<ll> PQ_HIGH;
typedef priority_queue<ll,VL,greater<ll>> PQ_LOW;//昇順

int main(){
  int h,w;cin>>h>>w;
  vector<vector<char>> a(h,vector<char>(w));
  vector<vector<char>> ans(0,vector<char>(0));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  int high=h;
  int width=w;
  VI yoko(w,0);
  VI tate(h,0);
  for(int i=0;i<h;i++){
    int key=0;
    for(int j=0;j<w;j++){
      if(a[i][j]=='#'){key=1;}
    }
    if(key==0){tate[i]=1;}
  }
  for(int i=0;i<w;i++){
    int key=0;
    for(int j=0;j<h;j++){
      if(a[j][i]=='#'){key=1;}
    }
    if(key==0){yoko[i]=1;}
  }
  for(int i=0;i<h;i++){
    if(tate[i]==0){
      vector<char> tmp(0);
      for(int j=0;j<w;j++){
        if(yoko[j]==0){
          tmp.push_back(a[i][j]);
        }
      }
      ans.push_back(tmp);
    }
  }
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}
