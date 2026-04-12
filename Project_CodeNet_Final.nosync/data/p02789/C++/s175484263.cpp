#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define rrep(i, n) for (int i = (int)n-1; i >= 0; --i)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

__attribute__ ((constructor))
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
}

signed main(){
  int n,m;
  cin >> n >> m;
  if(n==m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}