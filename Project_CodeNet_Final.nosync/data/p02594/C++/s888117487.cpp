#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define All(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
#define IN(a, b, x) (a<=x&&x<b)
using namespace std;
using ll = long long;
using Pair = pair<int,int>;
using Graph = vector<vector<ll>>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename t, typename u, typename Comp=less<>>
bool chmax(t& xmax, const u& x, Comp comp={}) { if(comp(xmax, x)) { xmax = x; return true; } return false;}
template<typename t, typename u, typename Comp=less<>>
bool chmin(t& xmin, const u& x, Comp comp={}) { if(comp(x, xmin)) { xmin = x; return true;} return false;}
const int INF = 1e9;
const ll infl = ll(1e18)+5;

int main(){
  int x;
  cin >> x;
  string ans;
  if(x >=30) ans = "Yes";
  else ans = "No";  
  cout <<  ans << endl;

}
