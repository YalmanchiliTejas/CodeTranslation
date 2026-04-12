#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

class Dice{
public:
  int t,s,e,n,w,b;
  Dice(){}
  Dice(int _t,int _s,int _e,int _n,int _w,int _b){
    t = _t; s = _s; e = _e; n = _n; w = _w; b = _b;
  }
  Dice moveEast(){
    return Dice(w,s,t,n,b,e);
  }
  Dice moveNorth(){
    return Dice(s,b,e,t,w,n);
  }
  Dice moveRight(){
    return Dice(t,e,n,w,s,b);
  }
};

void solve(){
}

int main(){
  int n;

  while(cin>>n,n){
    Dice d(1,2,3,5,4,6);
    int cnt = 1;

    rep(i,n){
      string s;
      cin>>s;
      if(s == "North"){
        d = d.moveNorth();
      }
      else if(s == "East"){
        d = d.moveEast();
      }
      else if(s == "West"){
        d = d.moveEast();
        d = d.moveEast();
        d = d.moveEast();
      }
      else if(s == "South"){
        d = d.moveNorth();
        d = d.moveNorth();
        d = d.moveNorth();
      }
      else if(s == "Right"){
        d = d.moveRight();
      }
      else{
        d = d.moveRight();
        d = d.moveRight();
        d = d.moveRight();
      }

      cnt += d.t;
    }

    cout<<cnt<<endl;
  }
}