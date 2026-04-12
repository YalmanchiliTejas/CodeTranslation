// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>
#include <random>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

bool comp(const Pl &a, const Pl &b){
  if(a.first != b.first)return a.first < b.first;
  else return a.second < b.second;
}

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<Pll> vec(n);
  rep(i, n)cin >> vec[i].first >> vec[i].second;
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  ll ma = -1, mi = linf;
  int mai = 0, mii = 0;
  rep(i, n){
    if(ma < vec[i].first){
      ma = vec[i].first;
      mai = i;
    }
    if(ma < vec[i].second){
      ma = vec[i].second;
      mai = i;
    }
    if(mi > vec[i].first){
      mi = vec[i].first;
      mii = i;
    }
    if(mi > vec[i].second){
      mi = vec[i].second;
      mii = i;
    }
  }
  ll rma = ma, bmi = mi;
  ll rmi = linf, bma = -1;
  if(mai != mii){
    rmi = vec[mii].first + vec[mii].second - mi;
    bma = vec[mai].first + vec[mai].second - ma;
  }
  rep(i, n){
    if(i != mai && i != mii){
      ll fi = vec[i].first, se = vec[i].second;
      if(fi > se)swap(fi, se);
      chmax(bma, fi);
      chmin(rmi, se);
    }
  }
  ll res1 = (rma - rmi) * (bma - bmi);
  if(mai == mii){
    cout << res1 << endl;
    return 0;
  }

  set<Pl> b;
  b.insert(mk(vec[mii].first + vec[mii].second - mi, -1));
  b.insert(mk(vec[mai].first + vec[mai].second - ma, -1));
  rep(i, n){
    if(i != mai && i != mii){
      b.insert(mk(min(vec[i].first, vec[i].second), i));
    }
  }
  while(true){
    Pl mini = *(b.begin());
    Pl maxi = *(b.rbegin());
    if(mini.second < 0)break;
    ll sec = vec[mini.second].first + vec[mini.second].second - mini.first;
    auto itr = b.begin();
    ++itr;
    if(maxi.first >= sec || maxi.first - mini.first >= sec - itr->first){
      b.erase(b.begin());
      b.insert(mk(sec, -1));
    }else{
      break;
    }
  }
  ll res2 = (b.rbegin())->first - (b.begin())->first;
  cout << min(res1, res2 * (ma - mi)) << endl;
	return 0;
}
