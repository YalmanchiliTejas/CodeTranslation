#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF 100100100100
#define inf 2001001001
#define MOD 1000000007
#define ALL(x) begin(x),end(x)
#define F first
#define S second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vii = vector<int>;
using vll = vector<ll>;
using priority_queue_small = priority_queue<int, vector<int>, greater<int> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>void show(const vector<T> &a) { for (int i = 0; i < (int)a.size(); ++i) cout << a[i] << (i != (int)a.size()-1 ? " " : "\n"); }
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
int dy[]={0, 1, -1, 0};
int dx[]={1, 0, 0, -1};

ll n, x;
ll pat[51], ban[51], sum[51];

ll eating(ll l, ll p) {
  if (l <= 1) {
    if (l == 0) {
      if (p > 0) return 1LL;
      else return 0;
    } else if (l == 1) {
      if (p >= 4) return 3LL;
      else if (p >= 3) return 2LL;
      else if (p >= 2) return 1LL;
      else return 0LL;
    } else {
      return 0;
    }
  }
  if (p <= 1) return 0LL;
  ll res = 0LL;
  if ((sum[l]-1) / 2 <= p-1) {
    res += pat[l-1] + 1;
    res += eating(l-1, p-sum[l-1]-2-(sum[l] == p));
  } else {
    res += eating(l-1, p-1);
  }
  return res;
}

int main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
  cin >> n >> x;
  pat[0] = 1, ban[0] = 0, sum[0] = 1; 
  erep(i, 1, n) {
    pat[i] = pat[i-1] * 2 + 1;
    ban[i] = ban[i-1] * 2 + 2;
    sum[i] = pat[i] + ban[i];
  }
  cout << eating(n, x) << endl;
  return 0;
}

