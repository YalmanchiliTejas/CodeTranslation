#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,int> pli;
typedef pair<int,int> pii;
typedef long double ld;
#define rep(i,a,b) for(ll i=a ; i<b ; i++)
#define qrep(que, ite) for(auto ite=begin(que) ; ite!=end(que) ; ite++)
const int max_n = 1e5;
const ll mod = 1e9+7;
const ll INF = 1LL<<60;
const int inf = 1e5;
//typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
ll gcd(ll a, ll b) { return a ? gcd(b%a, a) : b; }
int main(){
  int H,W;  cin>>H>>W;
  string s[H];
  rep(i,0,H){
    cin >> s[i];
  }
  map<int,int> ma;
  rep(i,0,H){
    bool ok=true;
    rep(j,0,W){
      if(s[i][j]!='.') ok=false;
    }
    if(ok){
      ma[i]++;
    }
  }
  rep(j,0,W){
    bool ok=true;
    rep(i,0,H){
      if(s[i][j]!='.') ok=false;
    }
    if(ok){
      rep(i,0,H){
        s[i][j] = 'o';
      }
    }
  }
  rep(i,0,H){
    if(ma[i]) continue;
    rep(j,0,W){
      if(s[i][j]!='o') cout<<s[i][j];
    }
    cout << endl;
  }
  return 0;
}
