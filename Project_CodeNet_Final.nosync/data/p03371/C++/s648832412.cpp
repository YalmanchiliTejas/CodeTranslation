#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
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
const int INF = 2e9;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll mini = min(x, y);
  ll maxi = max(x, y);
  ll ans1 = a * x + b * y;
  ll ans2=2 * c *maxi;
  ll ans3;
  if (x < y){
    ans3 = 2 * c * mini + b * (maxi - mini);
  }
  else{
    ans3 = 2 * c * mini + a * (maxi - mini);
  }
  ll ans = INF;
  chmin(ans, ans1);
  chmin(ans, ans2);
  chmin(ans, ans3);
  print(ans);
}