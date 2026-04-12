#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;
using namespace std;

#if __has_include("print.hpp")
  #include "print.hpp"
#endif

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MOD 1000000007

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef pair<ll, ll> p;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<p> v(m);
  vector<vector<int>> graph(n);
  vector<map<int, bool>> mp(n);
  rep(i, m) {
    cin >> v[i].first >> v[i].second;
    v[i].first--;v[i].second--;
    graph[v[i].first].push_back(v[i].second);
    graph[v[i].second].push_back(v[i].first);
    mp[v[i].first][v[i].second] = true;
    mp[v[i].second][v[i].first] = true;
  }

  vector<int> order(n-1);
  rep(i, n-1) order[i] = i+1;

  int res = 0;
  do {
    int now = 0;
    bool flag = false;
    for (int i = 0; i < n-1; ++i) {
      if(!mp[now][order[i]]){
        flag = true;
        break;
      }
      now = order[i];
    }
    if(!flag) res++;
  }while (next_permutation(ALL(order)));

  cout << res << endl;
}
