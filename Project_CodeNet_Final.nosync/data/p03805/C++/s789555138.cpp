#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

int main(){
  int n,m; cin >> n >> m;
  int G[n][n] = {};
  rep(i, m){
    int a, b; cin >> a >> b;
    a--; b--;
    G[a][b]++;
    G[b][a]++;
  }
  vi v;
  rep(i, n) v.pb(i);
  int ans = 0;
  do {
    for (int i = 1; i < n; i++) {
      if(G[v[i-1]][v[i]] == 0) break;
      if(i == n-1) ans++;
    }
  } while(next_permutation(v.begin()+1, v.end()));

  std::cout << ans << '\n';
}
