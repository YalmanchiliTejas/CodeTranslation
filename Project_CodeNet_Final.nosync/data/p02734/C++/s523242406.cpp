#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ;
#endif

#define equals(a,b) (fabs((a)-(b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

template <typename T>
void print_array(const T &ary, int size){
    REP(i,size){
        cout << ary[i] << " ";
    }
    cout << endl;
}

const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);
const int mod = 998244353;

struct mint {
    LL x; // typedef long long LL;
    mint(LL x=0):x( x >= 0 ? x%mod : x%mod+mod){}
    mint& operator+=(const mint a) {
      if ((x += a.x) >= mod) x -= mod;
      return *this;
    }
    mint& operator-=(const mint a) {
      if ((x += mod-a.x) >= mod) x -= mod;
      return *this;
    }
    mint& operator*=(const mint a) {
      (x *= a.x) %= mod;
      return *this;
    }
    mint operator+(const mint a) const {
      mint res(*this);
      return res+=a;
    }
    mint operator-(const mint a) const {
      mint res(*this);
      return res-=a;
    }
    mint operator*(const mint a) const {
      mint res(*this);
      return res*=a;
    }
    mint pow(LL t) const {
      if (!t) return 1;
      mint a = pow(t>>1);
      a *= a;
      if (t&1) a *= *this;
      return a;
    }
   
    // for prime mod
    mint inv() const {
      return pow(mod-2);
    }
    mint& operator/=(const mint a) {
      return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
      mint res(*this);
      return res/=a;
    }
  };

mint dp[3010][3010];

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    int N,S; cin >>N>>S;
    VI A(N);
    mint ans = 0;
    REP(i,N) cin >> A[i];
    REP(i,N){

        dp[i][0] += 1;
        REP(j,S+1){
            if(j-A[i] >= 0){
                dp[i+1][j] = dp[i][j] + dp[i][j-A[i]];
            }else{
                dp[i+1][j] = dp[i][j];
            }
            //cout << i+1 << " " << j << " " << dp[i+1][j].x << endl;
        }
        ans += dp[i+1][S];
    }
    cout << ans.x << endl;



}
