#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define R(i,n) for(int i = 0; i < (n); i++)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C &a4, C b4) { a4 = min(a4, b4); }
template<class C> void maxi(C &a4, C b4) { a4 = max(a4, b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

template<class T> ostream &operator<<(ostream& os, set<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}

template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> PP) {
  return os << "(" << PP.FI << "," << PP.SE << ")";
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 101;
const int P = 1e9 + 7;
int t[MAX];
int pot(int a,int w){
  int r = 1;
  while(w){
    if(w & 1){
      r = r * a % P;
    }
    w/=2;
    a = a * a % P;
  }
  return r;
}
int mul(int a,int b){
  return a * b % P;
}
void sub(int &a,int b){
  a -= b;
  if(a < 0)
    a+=P;
}
void add(int &a,int b){
  a += b;
  if(a >= P)
    a -= P;
}
PII licz(int po,int ko,int flo){
  int poo = po;
  int ma = 2e9;
  for(int i = po; i < ko; i++){
    mini(ma,t[i]);
  }
  PII res = {2,1};
  int ilema = -1;
  for(int i = po; i <= ko; i++){
    if(i == ko || t[i] == ma){
      ilema++;
      if(i > po){
        PII pom = licz(po, i, ma);
        res.FI = mul(res.FI, pom.FI);
        res.SE = mul(res.SE, (pom.SE + pom.FI)%P);
      }
      po = i + 1;
    }
  }
  debug(res);
  res.SE = mul(res.SE, pot(2, ilema));
  debug(res);
  sub(res.SE, res.FI);
  
  res.FI = mul(res.FI, pot(2, ma - flo - 1));
  add(res.SE,res.FI);
  debug(poo,ko,res);
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  int n;
  cin >> n;
  R(i,n){
    cin >> t[i];
  }
  PII res = licz(0,n,0);
  cout << res.SE << "\n";
}


