#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(long long i=0;i<n;++i)
#define REPR(i,n) for(long long i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb push_back
#define pf push_front
#define MP make_pair
#define SV(v) {for(long long sitr=0;sitr<v.size();++sitr){cin>>v[sitr];}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

int main(){

  int h, w;
  cin >> h >> w;

  string s[100];

  REP(i,h){
    cin >> s[i];
  }

  bool w_h[100] = {}, w_w[100] = {};

  REP(i,h){
    bool is_white = true;
    REP(j,w){
      if(s[i][j] == '#'){
        is_white = false;
        break;
      }
    }
    if(is_white){
      w_h[i] = true;
    }
  }

  REP(i,w){
    bool is_white = true;
    REP(j,h){
      if(s[j][i] == '#'){
        is_white = false;
        break;
      }
    }
    if(is_white){
      w_w[i] = true;
    }
  }

  REP(i,h){
    bool is_print = false;
    REP(j,w){
      if(!w_h[i] && !w_w[j]){
        cout << s[i][j];
        is_print = true;
      } 
    }
    if(is_print)
      cout << "\n";
  }
  return 0;
}

