#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <deque>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <array>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <chrono>
#include <random>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;
using str = string;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vs> vvs;
typedef vector<vc> vvc;
typedef vector<vb> vvb;
using P = pair<ll,ll>;
#define REP(i, n) for (ll i = 0; i < (int)(n); i++)
#define RREP(i, n) for (ll i = (int)(n)-1; i > -1 ; i--)
#define IN(T, x) T x;cin >> x;
#define AIN(T, a, n) vector<T> a(n);REP(i, n){cin >> a[i];}
#define A2IN(T1, a, T2, b, n) vector<T1> a(n);vector<T2> b(n);REP(i, n){cin >> a[i] >> b[i];}
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) SORT(a);reverse(ALL(a))
#define PB push_back
#define MP make_pair
#define PF first
#define PS second
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<typename A, size_t N, typename T>void Fill(A (&array)[N], const T &val){fill( (T*)array, (T*)(array+N), val );}
#define OUT(x) cout << x << endl;
#define OUTD(x) cout << fixed << x << endl;
#define BOUT(b) if(b){OUT("Yes");}else{OUT("No");}
const ll MOD = 1000000007;
const ll INF = 10e9;
const ld PI = 3.14159265369;
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
ll ddx[8] = {1,1,1,-1,-1,-1,0,0};
ll ddy[8] = {0,1,-1,0,1,-1,1,-1};

unsigned GetDigit(unsigned num){
    return std::to_string(num).length();
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  IN(ll,N);AIN(ll,A,N);
  ll dp[N][N];
  REP(i,N){
      dp[0][i] = A[i];
  }
  REP(i,N-1){
      REP(j,N-1){
          if(i+j+1>=N)continue;
          dp[i+1][j] = max(A[j]-dp[i][j+1],A[i+j+1]-dp[i][j]);
      }
  }
  OUT(dp[N-1][0]);
}