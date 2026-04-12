#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define fore(x, a) for(auto &&x:a) 
#define ITR(i,b,e) for(auto i=(b);i!=(e);++i)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define ALL(x) begin(x),end(x)
#define F first
#define S second
const int inf=1001001001;
const long long INF=1001001001001001001;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vii = vector<int>;
using vll = vector<ll>;
using priority_queue_small = priority_queue<int, vector<int>, greater<int> >;
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) {
    ITR(i,begin(v),end(v))os<<*i<<(i==end(v)-1?"":" ");return os;}
template<class T> istream& operator>>(istream &is,vector<T> &v) {
    ITR(i,begin(v),end(v)) is>>*i;return is;}
template<class T,class U> istream& operator>>(istream &is, pair<T,U> &p) {
    is>>p.first>>p.second;return is;}
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
int dy[]={0, 1, -1, 0};
int dx[]={1, 0, 0, -1};

int n;
int main() {
 cin.tie(0);
 ios::sync_with_stdio(false);
  cin >> n;
  vii a(n);
  rep(i, 0, n) cin >> a[i];
  deque<int> b;
  rep(i, 0, n) {
    if (n % 2) {
      if (i % 2) b.push_back(a[i]);
      else b.push_front(a[i]);
    } else {
      if (i % 2) b.push_front(a[i]);
      else b.push_back(a[i]);
    }
  }
  rep(i, 0, n) { 
    cout << b[i] << (i != n-1 ? " " : "\n");
  }
  return 0;
}

