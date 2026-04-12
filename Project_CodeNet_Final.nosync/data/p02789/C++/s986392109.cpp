#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define REVETSE(c) reverse((c).begin(),(c).end())
#define SUM(c) accumulate((c).begin(),(c).end(),0)
#define ALL(a)  (a).begin(),(a).end()
// int gcd(int a,int b){return b?gcd(b,a%b):a;}
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> T maxt(T x,T y) {
    if (x>y) return x;
    else return y;
}
template<class T> T mint(T x,T y) {
    if (x>y) return y;
    else return x;
}
//sort(v.rbegin(), v.rend(), [](auto& x, auto& y){return x[1] < y[1];});
//cout << fixed << setprecision(10) << ans << defaultfloat << endl;
typedef long long ll;
typedef vector<int> Vi;
typedef vector<ll> Vl;
typedef vector<double> Vd;
typedef vector<string> Vs;

long long m = 1e9+7, mod = 1e9+7;
//逆元　a/b の modをとるとき -> a*modinv(b)%mod
long long modinv(long long a, long long m = 1e9+7) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

/* //約数列挙
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}*/


int main() {
  int n,m;
  scanf("%d %d",&n,&m);
  if (n==m) printf("Yes");
  else printf("No");
  
}