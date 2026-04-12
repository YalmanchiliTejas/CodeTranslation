#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i >= 0; i--)
#define REP(i, m, n) for (int i = (int)(m); i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main(){
  ll n, x, m;
  cin >> n >> x >> m;
  set<ll> st;
  vector<ll> a;

  st.insert(x);
  a.push_back(x);
  rep(i, 100010){
    x = (x*x) % m;
    if(st.count(x)) break;
    st.insert(x);
    a.push_back(x);
  }

  vector<ll> b;
  bool IN = false;
  rep(i, a.size()){
    if(!IN) if(a[i] == x) IN = true;
    if(IN) b.push_back(a[i]);
  }
  ll k = a.size() - b.size();
  ll l = b.size();
  ll d = (n-k) / l;
  ll r = (n-k) % l;
  ll pre = 0;
  ll sum = 0;
  ll rest = 0;
  rep(i, k) pre += a[i];
  rep(i, l) sum += b[i];
  rep(i, r) rest += b[i];
   
  cout << pre + sum * d + rest << endl;

  return 0;
}

