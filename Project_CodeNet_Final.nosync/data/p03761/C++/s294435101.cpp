#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define per(i,n) for(ll i = n-1; i >= 0; i--)
#define REP(i,n) for(ll i = 1; i < n; i++)
#define PER(i,n) for(ll i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPP = vector<vP>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<char, int> mp;
  for(char c = 'a'; c <= 'z'; c++) mp[c] = inf;
  rep(i,n) {
    string s;
    cin >> s;
    int m = sz(s);
    for(char c = 'a'; c <= 'z'; c++) {
      int cnt = 0;
      rep(j,m) if(s[j] == c) cnt++;
      chmin(mp[c],cnt);
    }
  }
  for(P p : mp) {
    rep(i,p.se) cout << (char)p.fi;
  }
  cout << endl;
}