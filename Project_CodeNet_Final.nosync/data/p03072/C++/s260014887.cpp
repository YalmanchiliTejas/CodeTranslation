#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (b) - 1; i >= (a); i--)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define ALL(i) (i).begin(),(i).end()
#define RALL(i) (i).begin(),(i).end(),greater<int>()

#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second

typedef long long ll;
#define TENNINE 1000000005
#define TENFIVE 100005
#define TENFIVE2 200005
// #define int long long
const int INF = 999999999;
const int MOD = 1e9 + 7;
const double EPS = 1e9 + 7;
const double PI = acos(-1);
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

inline int in(){int x;std::cin>>x;return x;}

using lint = long long;
using pint = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int> >;
using vl = vector<long long>;
using vp = vector<pint>;

template <typename T> void print(T x) { std::cout << x << '\n'; }
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
  std::fill((T*)array, (T*)(array + N), val);
}
signed main(){
  int N;
  int H[104]={0};
  cin>>N;
  int ans=1;
  rep(i,N)cin>>H[i];
  RFOR(i,1,N){
    int count = 0;
    RFOR(j,0,i){
      if(H[j] <= H[i] )count++;
      else break;
    }
    if( count == i )ans++;
  }
  print(ans);
  return 0;
}
