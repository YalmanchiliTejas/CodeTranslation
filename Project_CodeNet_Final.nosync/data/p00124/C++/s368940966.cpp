#include <bits/stdc++.h>
using namespace std;

// infty
#define ULLINF (ULLONG_MAX)
#define LLINF  (LLONG_MAX)
#define IINF   (INT_MAX)
#define INF    (1<<29)

// math
#define Sq(x) ((x)*(x))

// container utility
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define EACH(it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();it++)

// rep
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

// typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;

typedef long long ll;

// pair util
#define FST first
#define SND second

// range validator
#define CK(n,a,b) (a<=n && n<b)

// conversion
template<class T> inline string toStr(T a) { ostringstream oss_; oss_ << a; return oss_.str(); }
inline int toInt(string s) { return atoi(s.c_str()); }

// prime
bool isPrime(int a) { for(int i=2; i*i <=a; i++) if(a%i == 0) return false; return true; }

int const dx[] = {-1,0,1,0,-1,1,1,-1};
int const dy[] = {0,-1,0,1,-1,-1,1,1};

//////////////////////////////////////////////////////////////


int main() {
  int N;
  bool blank = 0;
  while(cin >> N && N) {
    if(blank) cout << endl;
    blank = 1;
    vector<pair<PII, string> > vec;
    for(int i=0; i<N; i++) {
      string s; cin >> s;
      int a, b, c;
      cin >> a >> b >> c;
      vec.push_back(MP(MP(-a*3-c*1, i), s));
    }
    sort(ALL(vec));
    
    EACH(it, vec) {
      cout << it->second << "," << -it->first.first << endl;
    }
  }
  
  
  return 0;
}