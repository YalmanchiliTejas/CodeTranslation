#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

const int MOD = 1000000007;

struct CumulativeSum {
  vector<long long> csum;
  template<typename T>
  CumulativeSum(vector<T> input) : csum(input.size() + 1, 0) {
    for(int i = 0; i < (int)input.size(); i++) csum[i+1] = csum[i] + input[i];
  }
  long long query(int l, int r) { /* 0-indexed, inclusive */ return csum[r+1] - csum[l]; }
};

int main() {
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  CumulativeSum cs(a);


  ll ans = 0;
  rep(i,1,n) {
    ll q = cs.query(0, i-1) % MOD;
    ans += (a[i] * q) % MOD;
    ans = ans % MOD;
  }
  cout << ans << endl;
}
