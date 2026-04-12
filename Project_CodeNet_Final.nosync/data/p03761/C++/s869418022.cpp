#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define YY cout << "Yes" << endl;
#define NN cout << "No" << endl;
#define ve vector
#define pint pair<int,int>
const int INF = 1000000007;
const long double EPS = 1e-15;
const long double PI = acos(-1);
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
// *max_element(all(d))
// priority_queue<int,vector<int>,greater<int>>
int solve(){
  int n;
  cin >> n;
  vector<string>s(n);
  rep(i,n)cin >> s[i];
  rep(i,n)sort(all(s[i]));
  int msi = INF;
  rep(i,n)msi = min(msi,(int)s[i].size());
  string ans;
  string tmp;
  rep(i,n)if(msi == s[i].size())tmp = s[i];
  rep(i,tmp.size()){
    bool check = true;
    REP(j,1,n){
      bool can = false;
      rep(k,s[j].size()){
        if(tmp[i] == s[j][k]){
          can = true;
          s[j][k] = 'A';
          k = s[j].size() - 1;
        }
      }
      if(!can)check = false;
    }
    if(check){
      ans.push_back(tmp[i]);
    }
  }
  sort(all(ans));
  cout << ans << endl;
  return 0; 
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16);
  solve();
  return 0;
}