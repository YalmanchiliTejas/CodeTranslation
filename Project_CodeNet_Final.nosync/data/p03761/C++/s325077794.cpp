#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vll = vector<vl>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1e9+7;
const ll INF = 2e15;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int main(){
  string abc = "abcdefghijklmnopqrstuvwxyz";
  ll n;
  cin >> n;
  vll alpha(n, vl(26, 0));
  rep(i, n)
  {
    string s;
    cin >> s;
    rep(j,sz(s)){
      alpha[i][s[j] - 'a']++;
    }
  }
  string ans = "";
  rep(i, 26){
    ll mini = INF;
    rep(j, n){
      chmin(mini,alpha[j][i]);
    }
    rep(k,mini){
      ans += abc[i];
    }
  }
  print(ans);
}