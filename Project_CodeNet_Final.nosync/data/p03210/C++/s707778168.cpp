#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define fore(x, a) for(auto &x : a)
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
template<class T>using vv = vector<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
template<class T>void show(const vector<T> &a) { for (int i = 0; i < (int)a.size(); ++i) cout << a[i] << (i != (int)a.size()-1 ? " " : "\n"); }
template<class T>T gcd(T a, T b){ return b ? gcd(b, a % b) : a; }
template<class T>T lcm(T a, T b){ return a / gcd(a, b) * b; }
int dy[]={0, 1, -1, 0};
int dx[]={1, 0, 0, -1};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    int x;
    cin >>  x;
    if (x == 7 || x == 5 || x == 3) cout << "YES" << endl;
    else cout << "NO" << endl;    
    return 0;
}

