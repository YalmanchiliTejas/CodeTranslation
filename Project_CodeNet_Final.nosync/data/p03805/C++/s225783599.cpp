#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

int main(){
  ll n, m;
  cin >> n >> m;
  vvll graph(n);
  rep(i, 0, m){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  vrep(i, graph) sort(all(i));
  vll order(n - 1);
  iota(all(order), 1);
  ll ans = 0;
  do{
    bool check = true;
    rep(i, 0, n - 2) if(find(all(graph[order[i]]), order[i + 1]) == graph[order[i]].end()) check = false;
    if(find(all(graph[0]), order[0]) == graph[0].end()) check = false;
    if(check) ans++;
  }while(next_permutation(all(order)));
  cout << ans << endl;
}