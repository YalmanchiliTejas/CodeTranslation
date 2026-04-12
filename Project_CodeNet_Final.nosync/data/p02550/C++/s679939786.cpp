#pragma GCC optimize("Ofast")
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <math.h> 
#include <functional>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod2 = 1000000007;
constexpr ll mod = 998244353;
const int dx[8] = {1, 0, -1, 0,1,1,-1,-1};
const int dy[8] = {0, 1, 0, -1,1,-1,1,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// --------------------------------------------------------------------------



int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N,X,M;
  cin >> N >> X >> M;
  X %= M;
  ll sum = X;
  if(N <= M){
    for(int i=1; i<N; i++){
      X = (X*X)%M;
      sum += X;
    }
    cout << sum << "\n";
    return 0;
  }
  vector<int> nxt(M,-1);
  ll cnt = N-1;
  while(1){
    if(nxt[X] != -1){
      ll now = nxt[X];
      ll roop = 1;
      X = nxt[X];
      ll now_sum = X;
      while(nxt[X] != now){
        X = nxt[X];
        now_sum += X;
        roop++;
      }
      sum += cnt/roop * now_sum;
      cnt %= roop;
      while(cnt){
        X = nxt[X];
        sum += X;
        cnt--;
      }
      cout << sum << "\n";
      return 0;
    }else{
      nxt[X] = (X*X)%M;
      X = (X*X)%M;
      sum += X;
    }
    cnt--;
  }
  return 0;
}