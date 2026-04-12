#include <bits/stdc++.h>
#include <typeinfo>
#include <cxxabi.h>
#ifdef LOCAL
  #include "dbgtoki.hpp"
  #define DUMP(i) dump((string)TOSTRING(i), demangle(typeid(i).name()), __LINE__ , i) 
DbgTimer D_t;
  #define TSTART() D_t.start()
  #define TSTOP() D_t.stop()
#else
  #define DUMP(i) 
  #define TSTART()
  #define TSTOP()  
#endif
 
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(s) (s).begin(), (s).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()) , v.end());
using namespace std;
typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int EPS = 1e-9;

int main (){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r,g,b;
  while(cin >> r >> g >> b){
    TSTART();
    string ans;
    int value = g*10 + b;
    if(value % 4 == 0)ans = "YES";
    else ans = "NO";
    cout << ans << endl;
    TSTOP();
  }
    return 0;
}

