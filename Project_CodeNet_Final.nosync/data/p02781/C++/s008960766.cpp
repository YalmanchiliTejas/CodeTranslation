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

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double EPS = (1e-10);

LL dp[110][5][2] = {};

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(12);

    string N; cin >> N;
    int K; cin >> K;
    int len = N.length();

    VI sN(len);
    REP(i,len){
        sN[i] = N[i]-'0';
    }
    if(sN[0] == 1){
        dp[0][1][0] = 1;
        dp[0][0][1] = 1;
    }else{
        dp[0][1][0] = 1;
        dp[0][1][1] = sN[0] - 1;
        dp[0][0][1] = 1;
    }

    FOR(i,1,len){
        FOR(j,0,K+1){
            if(sN[i] == 0){
                dp[i][j][0] = dp[i-1][j][0];
                if(j == 0) dp[i][j][1] = dp[i-1][j][1];
                else dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][1] * 9 ;
            }else{
                if(j != 0) dp[i][j][0] = dp[i-1][j-1][0];
                if(j == 0) dp[i][j][1] = dp[i-1][j][1]  + dp[i-1][j][0];

                else dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j-1][1] * 9 + dp[i-1][j][0] + dp[i-1][j-1][0]*(sN[i]-1);
            }

        }
    }

    //REP(i,len) REP(j,K){
    //    cout << "dp[i][j] "<<i << " " << j << endl;
    //    cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
    //}

    LL ans = 0;
    REP(i,2){
        ans += dp[len-1][K][i];
    }
    cout << ans << endl;



}
