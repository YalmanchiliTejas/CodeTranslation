#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define sz(x) int(x.size())
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
const int INT_INF = 1 << 30;
#define MOD 1000000007LL
#define PI 3.141592653589793
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N;
  cin >> N;
  vll dp(N, -INF);
  int ans = 1;
  for(int i = 0; i < N; i++){
    ll A;
    cin >> A;
    if(i == 0) dp.at(0) = A;
    else{
      int ok = N-1;
      int ng = -1;
      while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(dp.at(mid) < A) ok = mid;
        else ng = mid;
      }
      dp.at(ok) = A;
      chmax(ans, ok+1);
    }
  }
  cout << ans << endl;
}