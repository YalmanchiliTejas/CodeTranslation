//Self-control leads to consistency.
#include <bits/stdc++.h> 
using namespace std; 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define flash ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define debug(x) cerr << " - " << #x << ": " << x << endl;
#define debugs(x, y) cerr << " - " << #x << ": " << x << " " << #y << ": " << y << endl;
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)x.size()
#define ll long long
#define INF 1000000000
#define MOD 1000000007
#define pb push_back
#define ve vector<ll>
#define dos pair<ll,ll>
#define vedos vector<dos>
#define rand mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define EPS 0.000001
struct greateri
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
int main()
{
  //flash;
  ll x;
  cin>>x;
  if(x>=30)cout<<"Yes";
  else cout<<"No";
  return 0;
}