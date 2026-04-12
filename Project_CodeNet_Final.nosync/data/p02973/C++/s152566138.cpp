#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define AND(x,y,z) 
#define DUMP(xs) for (auto x:xs) cout<<x<<' ';cout<<endl
#define DUMPP(xs) for (auto x:xs) cout<<'('<<x.first<<','<<x.second<<')';cout<<endl
#define FOR(i,a,b) for (ll i=(ll)(a);i<(ll)(b);++i)
#define OUT(x) cout<<x<<endl
#define REP(i,n) FOR(i,0,n)
#define YES(cond) cond ? OUT("YES") : OUT("NO")
#define Yes(cond) cond ? OUT("Yes") : OUT("No")

template<class T> T gcd(const T x,const T y){if(!y){return x;}return gcd(y,x%y);}
template<class T> T lcm(const T x,const T y){return x/gcd(x,y)*y;};
template<class T> T modpow(const T x,const T n,const T mod) {
  T res=1;while(n>0){if(n%2)res=res*x%mod;x=x*x%mod;n/=2;};return res;
}
template<class T> bool alltrue(const T &a){return all_of(ALL(a),[](bool x){return x;});}
template<class T> bool anytrue(const T &a){return any_of(ALL(a),[](bool x){return x;});}
template<class T> bool contain(const T &a,const T &b){for(auto x:b){if (a.find(x)==a.end()){return false;}}return true;}
template<class T> bool mmax(T &m,const T q){ if (m < q) {m = q; return true;} else return false; }
template<class T> bool mmin(T &m,const T q){ if (m > q) {m = q; return true;} else return false; }
template<class T> int siz(const T &a) {return (int)a.size();}
template<class T> set<T> devisers(T n) {
  set<T> res;for(T i=1;i<(T)sqrt(n)+1;i++){if(n%i==0){res.insert(i);res.insert(n/i);}}return res;
}
template<class T> void concat(T &a, const T &b){a.insert(a.end(),b.begin(),b.end());}
template<class T> void getand(const T &a,const T &b,T &c) {
  set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}
template<class T> void getor(const T &a,const T &b,T &c) {
  set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
}

typedef long long ll;
typedef pair<ll, ll> P;

const int MOD=1e9+7;

void LIS(vector<int> vec) {
  deque<int> res{vec[0]};
  DUMP(res);
  FOR(i,1,vec.size()) {
    auto it = lower_bound(ALL(vec),vec[i]);
    if (it==vec.begin()) res.push_front(vec[i]);
    else res[it-vec.begin()-1]++;
    DUMP(res);
  }
  OUT(res.size());
}

int main() {
  // 使う色の最小数
  // LISで貪欲的に全部が使われるまで繰り返すのは？
  int N;cin>>N;
  vector<int> AS(N);
  REP(i,N) cin>>AS[i];

  deque<int> res{AS[0]};
  FOR(i,1,N) {
    auto it = lower_bound(ALL(res),AS[i]);
    if (it==res.begin()) {
      res.push_front(AS[i]);
    } else {
      res[it-res.begin()-1]=AS[i];
    }
  }
  OUT(res.size());

  return 0;
}