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
void hey(){ cout <<"hey" <<endl; }


int main() {
  int N; cin >>N;
  vector<ll> A(N); rep(i, N) cin >>A[i];
  ll res = -INF;

  if (N % 2 == 0){
    int n2 = N/2;
    vector<vector<ll>> dp(N, vector<ll>(2, -INF));
    for (int i=0; i<n2; i++){
      if (i == 0){
        dp[i][0] = A[i*2];
        dp[i][1] = A[i*2];
      }else{
        // 0回飛ばしてるところから遷移
        chmax(dp[i][0], dp[i-1][0] + A[i*2]);
        chmax(dp[i][1], dp[i-1][0] + A[i*2+1]);

        // 1回飛ばしてるところから遷移
        chmax(dp[i][1], dp[i-1][1] + A[i*2+1]);
      }
    }
    chmax(res, dp[N/2-1][0]);
    chmax(res, dp[N/2-1][1]);

    ll tmp = 0;
    rep(i, n2) tmp += A[i*2+1];
    chmax(res, tmp);

    cout <<res <<endl;
  }else{
    int n2 = N/2;
    /*
    A[0]始まりなら2回飛ばせる
    A[1]始まりなら1回飛ばせる
    A[2]始まりなら0回飛ばせる
    */
    vector<vector<ll>> dp(N, vector<ll>(3, -INF));
    for (int i=0; i<n2; i++){
      if (i == 0){
        dp[i][0] = A[i*2];
        dp[i][1] = A[i*2];
        dp[i][2] = A[i*2];
      }else{
        // 0回飛ばしてるところから遷移
        chmax(dp[i][0], dp[i-1][0] + A[i*2]);
        chmax(dp[i][1], dp[i-1][0] + A[i*2+1]);
        chmax(dp[i][2], dp[i-1][0] + A[i*2+2]);

        // 1回飛ばしてるところから遷移
        chmax(dp[i][1], dp[i-1][1] + A[i*2+1]);
        chmax(dp[i][2], dp[i-1][1] + A[i*2+2]);

        // 2回飛ばしてるところから遷移
        chmax(dp[i][2], dp[i-1][2] + A[i*2+2]);
      }
    }
    chmax(res, dp[n2-1][0]);
    chmax(res, dp[n2-1][1]);
    chmax(res, dp[n2-1][2]);

    dp.assign(N, vector<ll>(2, -INF));
    for (int i=0; i<n2; i++){
      if (i == 0){
        dp[i][0] = A[i*2+1];
        dp[i][1] = A[i*2+1];
      }else{
        // 0回飛ばしてるところから遷移
        chmax(dp[i][0], dp[i-1][0] + A[i*2+1]);
        chmax(dp[i][1], dp[i-1][0] + A[i*2+1+1]);

        // 1回飛ばしてるところから遷移
        chmax(dp[i][1], dp[i-1][1] + A[i*2+1+1]);
      }
    }
    chmax(res, dp[n2-1][0]);
    chmax(res, dp[n2-1][1]);

    ll tmp = 0;
    rep(i, n2) tmp += A[i*2+2];
    chmax(res, tmp);

    cout <<res <<endl;
  }
}
