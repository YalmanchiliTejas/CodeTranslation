#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> struct edge { int from, to; T cost;};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}


int N;
const int MAX_N = 3010;

int main() {
  cin >>N;
  vector<int> A(N); rep(i, N) cin >>A[i];
  vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_N, 0));
  rep(i, N) dp[i][i] = 0;
  // dp[i][j]...[i,j) が残っている時から出発して両者最善を尽くした結果のX-Yの値
  for (int len=1; len<=N; len++){
    for (int i=0; i+len<=N; i++){
      int j = i + len;
      // j-iが残りの石の個数
      if ((N-len) % 2 == 0){
        // 取った石が偶数個なので今の局面が先手番
        dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j-1]);
      }else{
        // 今の局面が後手番
        dp[i][j] = min(dp[i+1][j] - A[i], dp[i][j-1] - A[j-1]);
      }
    }
  }
  cout <<dp[0][N] <<endl;
}
