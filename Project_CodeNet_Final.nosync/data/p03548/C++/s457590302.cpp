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

#define GETTYPE(i) 
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#define ALL(s) (s).begin(), (s).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()) , v.end());
using namespace std;
typedef long long unsigned int llu;
typedef long long ll;

const int EPS = 1e-9;

int main (){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,y,z;
  while(cin >> x >> y >> z){
    TSTART();

    int ans = 0;
    while(x - y - z * 2 >= 0){
      ans++;
      x -= y + z;
    }
    cout << ans << endl;
    TSTOP();
  }
  return 0;
}
