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
  int n; cin >> n;
  vvi G(n, vi(26));
  rep(i, n){
    string s; cin >> s;
    for(char c : s){
      G[i][c-'a']++;
    }
  }
  vi C(26,100);
  rep(i, n){
    rep(c, 26){
      chmin(C[c], G[i][c]);
    }
  }
  string ans;
  rep(c, 26){
    rep(i, C[c]){
      ans += (char)('a'+c);
    }
  }
  std::cout << ans << '\n';
}
