#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define ALL(x) (x).begin(),(x).end()
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;
using P=pair<int,int>;
v<int> a,b;
int solve(int N,int X){
  if(N==0 && X>=1) return 1;
  if(X<=1) return 0;
  if(1<=X && X<= 1+a[N-1]){
    return solve(N-1,X-1);
  }
  if(2+a[N-1]<=X && X<=2+2*a[N-1]){
    return 1+b[N-1]+solve(N-1,X-a[N-1]-2);
  }
  if(X==3+2*a[N-1]) return b[N];
}

signed _main(){
  int N,X; cin >> N >> X;
  a.assign(50+10,0);
  b.assign(50+10,0);
  a[0]=1;
  b[0]=1;
  for(int i=1;i<=N;i++){
    a[i]=2*a[i-1]+3;
    b[i]=2*b[i-1]+1;
  }
  cout << solve(N,X) << endl;
  return 0;
}
