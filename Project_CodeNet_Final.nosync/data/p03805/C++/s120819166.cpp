#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<set<int>> G(N);
  int a, b;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    a--;
    b--;
    G[a].insert(b);
    G[b].insert(a);
  }

  vector<int> v(N);
  for(int i = 0; i < N; i++){
    v[i] = i;
  }

  int ans = 0;
  do{

    if(v[0] == 0){
      bool ok = true;
      for(int i = 0; i < N-1; i++){

        if(G[v[i]].find(v[i+1]) == G[v[i]].end()){
          ok = false;
        }
      }
      if(ok){
        ans++;
      }
    }

  } while(next_permutation(v.begin(), v.end()));
  
  cout << ans << endl;

  return 0;
}
