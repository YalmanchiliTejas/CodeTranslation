#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b) for (int i = a; i < (b); ++i)
#define all(x) (x).begin(),(x).end()
#define YY cout << "Yes" << endl
#define NN cout << "No" << endl
const int INF = 1000000007;
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
bool g[10][10];
int solve(){
  int n,m;
  cin >> n >> m;
  vector<int>s(n);
  rep(i,n)s[i] = i;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a][b] = true;
    g[b][a] = true;
  }
  int ans = 0;
  do{
    if(s[0] != 0)continue;
    bool can = true;
    rep(i,n - 1)if(g[s[i]][s[i + 1]] != true)can = false;
    if(can)ans++;
  }while(next_permutation(s.begin(),s.end()));
  cout << ans << endl;
  return 0;
}
int main(){
  // ios::sync_with_stdio(false);cin.tie(nullptr);
  // cout << fixed;cout << setprecision(16) << endl; 
  solve();
  return 0;
} 