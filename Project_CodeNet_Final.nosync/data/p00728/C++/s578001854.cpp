#include <algorithm>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <stack>
#include <set>
#include <vector>
#include <numeric>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pii;

const int INF = 1 << 29;
const double EPS = 1e-10;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
  return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
  os<<'[';
  rep(i,a.size()) os<<(i?" ":"")<<a[i];
  return os<<']';
}



int main() {
  for (int n; cin >> n, n != 0; ) {
    vi s(n);
    rep(i, n) cin >> s[i];

    cout << (accumulate(all(s), 0) - *max_element(all(s)) - *min_element(all(s))) / (n - 2) << endl;
  }
  
  
  return 0;
}