#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;
#define MOD 1000000007LL

int main(){
  ll N, K;
  cin >> N >> K;
  ll ans = 0;
  for(ll b = K+1; b <= N; b++){
    //bで割ってK以上余るN以下の数
    ans += N/b * (b-K);
    if(K == 0) ans--; //0を除外
    ll ex = max(0LL, N%b - K + 1LL);
    ans += ex;
  }
  cout << ans << endl;
}