#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define All(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()   //reverse
#define strall(v) (v).cbegin(),(v).cend() //const_itterator
#define IN(a, b, x) (a<=x&&x<b)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<ll>>;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<typename t, typename u, typename Comp=less<>>
bool chmax(t& xmax, const u& x, Comp comp={}) { if(comp(xmax, x)) { xmax = x; return true; } return false;}
template<typename t, typename u, typename Comp=less<>>
bool chmin(t& xmin, const u& x, Comp comp={}) { if(comp(x, xmin)) { xmin = x; return true;} return false;}
const int INF = 1e9;
const ll infl = ll(1e18)+5;
/*
*ios::sync_with_stdio(false);
*cin.tie(0);
*/
ll solve(int n,ll x){
  if(n == 0) return 1;//レベル0 
  ll len = (1LL<<(n+1)) -3;
  ll num = (1LL<<n) - 1;
  if(x == 1) return 0;
  else if(x <= len+1) return solve(n-1, x-1);
  else if(x <= len+2) return num+1;
  else if(x <= (len+1)*2) return num+1+solve(n-1,x-len-2);
  else return num*2 + 1;

}


int main(){
  int N; long long X;
    cin >> N >> X;
    cout << solve(N, X) << endl;
}