#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define endl "\n"
using Edge = pair<int,ll>;
using Graph = vector<vector<Edge>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(void){
  ll a,b,c,x,y; cin >> a >> b >> c >> x >> y;
  ll ans = 1001001001001001;
  FOR(i,0,100000){
    ll price = c*i*2;
    price += a*(max(0LL,x-i)) + b*(max(0LL,y-i));
    chmin(ans,price);
  }

  cout << ans << endl;
}


