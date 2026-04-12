#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <cstring>
#include <cassert>
#include <chrono>
#include <random>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

#ifdef QLEG_DEBUG
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << '{'; string sep; for (const auto& x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll, ll>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);

  ll N, X, M; cin>>N>>X>>M;

  vector<ll> v = {X};
  vector<int> lst(M, -1);
  lst[X] = 0;
  int l = -1;
  while (1) {
    ll y = v.back() * v.back() % M;
    if (lst[y] != -1) {
      l = lst[y];
      break;
    }
    lst[y] = v.size();
    v.pb(y);
  }
  ll per = accumulate(v.begin()+l, v.end(), 0LL);
  ll res = accumulate(v.begin(), v.begin() + min(N, (ll)l), 0LL);
  dbg(l,per,res);
  N = max(N-l, 0LL);
  int K = v.size() - l;
  res += per * (N/K) + accumulate(v.begin()+l, v.begin()+l+N%K, 0LL);

  cout << res << '\n';
}
