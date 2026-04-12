#include <string>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;

const bool online_judge =
#ifdef ONLINE_JUDGE
  true
#else
  false
#endif
  ;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define all(v)  (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define eb emplace_back
#define SZ(a) ((int)((a).size()))
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,n) for(int i = 1; i <= n; i++)
#define rep3(i,n) for(int i = n-1; i >= 0; i--)
#define tag(i,v) rep(i,SZ(v))
#define _trace(x) #x << " = " << (x)
#define trace(x)  { if(!online_judge) cerr << _trace(x) << endl; }
#define trace2(x,y) { if(!online_judge) cerr << _trace(x) << " " << _trace(y) << endl; }
#define trace3(x,y,z) { if(!online_judge) cerr << _trace(x) << " " << _trace(y) << " " << _trace(z) << endl; }
#define tracev(x) { if(!online_judge) { cerr << #x << " = "; tag(__i, x) { cerr << x[__i] << ","; } cerr << endl; } }
#define fst get<0>
#define snd get<1>
#define thd get<2>
#define divup(x,y) ((x)/(y)+(0<((x)%(y))))
#define mp make_tuple
#define range(x,a,b) ((x) >= (a) && (x) <= (b))

const int inf = 1LL << 60;
int toInt(string s) {int res; stringstream ss; ss<<s; ss>>res; return res; }
string toString(int n) { stringstream ss; ss<<n; return ss.str(); }

int a,b,c,d,e,f;

void run() {

  /* entry point */
  int n;
  while(cin >> n){
    if(n == 0)
      break;
    vs v(n);
    rep(i,n)
      cin >> v[i];

    a = 1;
    b = 2;
    c = 3;
    d = 5;
    e = 4;
    f = 6;

    int ans = 1;
    
    tag(i,v){
      string s = v[i];
      int tmp;
      if(s == "North"){
        tmp = a;
        a = b;
        b = f;
        f = d;
        d = tmp;
      }
      else if(s == "East"){
        tmp = a;
        a = e;
        e = f;
        f = c;
        c = tmp;
      }
      else if(s == "West"){
        tmp = a;
        a = c;
        c = f;
        f = e;
        e = tmp;
      }
      else if(s == "South"){
        tmp = a;
        a = d;
        d = f;
        f = b;
        b = tmp;
      }
      else if(s == "Left"){
        tmp = b;
        b = e;
        e = d;
        d = c;
        c = tmp;
      }
      else if(s == "Right"){
        tmp = b;
        b = c;
        c = d;
        d = e;
        e = tmp;
      }
      else
        assert(false);
      ans += a;
    }

    cout << ans << endl;
  }

}

#undef int

int main(int argc, char *argv[]) {

  #if 0
  if(online_judge){
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
  }
  #endif

  run();

  return 0;

}