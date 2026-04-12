#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long ll;
typedef ll li;
typedef pair<int,int> PI;
#define EPS (1e-10L)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(),a.end()
#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)
void pkuassert(bool t){t=1/t;};
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};

char tr;

string in[4][13];

int c2i(char c){
  if(c=='A') return 14;
  if(c=='T') return 10;
  if(c=='J') return 11;
  if(c=='Q') return 12;
  if(c=='K') return 13;
  return c-'0';
}

void solve(){
  rep(i,4)rep(j,13) cin >> in[i][j];

  int te=0;
  int ns=0;
  rep(i,13){
    PI num1(0,0),num2(0,0);
    rep(j,4){
      if(in[j][i][1]==tr){
        int co=c2i(in[j][i][0]);
        num1=max(num1,mp(co,j));
      }
      if(in[j][i][1]==in[te][i][1]){
        int co=c2i(in[j][i][0]);
        num2=max(num2,mp(co,j));
      }
    }
    if(num1.F){
      ns += num1.S&1;
      te=num1.S;
    }else{
      ns += num2.S&1;
      te=num2.S;      
    }
    //cout << "nesw"[te] << endl;
  }

  if(ns>6) cout << "EW " << ns-6 << endl;
  else cout << "NS " << 7-ns << endl;
}

int main(int argc, char *argv[])
{
  while(cin >> tr && tr!='#') solve();
  return 0;
}