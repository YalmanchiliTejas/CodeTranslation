#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
#define VAR(type,...) type __VA_ARGS__;in(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);each(x, name)in(x)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define rrep(i,a,b) for(int i=(a-1);i>=(b);--i)
#define each(x,v) for(auto &x:(v))
#define all(x) (x).begin(),(x).end()
#define print(x) cout<<(x)<<endl
void in(){} template<class T,class... U> void in(T &t,U &...u){cin>>t;in(u...);}
void solve();
int main(){cin.tie(0);ios::sync_with_stdio(0);solve();}

void solve() {
  VAR(int, A, B, C, X, Y);
  ll ans = 0;
  if (C <= A / 2) {
    ans += C * X * 2ll;
    Y = max(Y - X, 0);
    X = 0;
  }
  if (C <= B / 2) {
    ans += C * Y * 2ll;
    X = max(X - Y, 0);
    Y = 0;
  }
  if (C <= (A + B) / 2) {
    int cnt = min({X, Y});
    ans += C * cnt * 2ll;
    Y -= cnt;
    X -= cnt;
  }
  ans += A * max(X, 0) + B * max(Y, 0);
  print(ans);
}
