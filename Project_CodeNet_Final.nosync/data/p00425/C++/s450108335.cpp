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
  int t, s, e, n, w, b; //上,南,東,北,西,下
  Dice(){}
  Dice(int t, int s, int e, int n, int w, int b) :
    t(t), s(s), e(e), n(n), w(w), b(b) {}

  // 上の面が東の面に来るように回転
  Dice moveEast()  { return Dice(w, s, t, n, b, e); }
  // 上の面が北の面に来るように回転
  Dice moveNorth() { return Dice(s, b, e, t, w, n); }
  // 南の面が西の面に来るように回転
  Dice moveRight() { return Dice(t, e, n, w, s, b); }

  bool operator==(const Dice &d)const{
    return
      t == d.t && s == d.s && e == d.e &&
      n == d.n && w == d.w && b == d.b;
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