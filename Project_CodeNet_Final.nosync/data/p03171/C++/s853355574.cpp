#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

//typedef
typedef long long LL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<LL, LL> PLL;

//conversion
inline LL toLong(string s) {LL v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define UNTIL(p) while(!(p))

//constant
const double EPS = 1e-5;
const double PI  = acos(-1.0);

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define PUTS(x) cout << (x) << endl;

LL dp[3005][3005][2] = {0};
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n;
    cin>>n;
    VL a(n);
    REP(i,n)cin>>a[i];
    LL sum = 0;
    REP(i,n)sum += a[i];

    REP(i,n)dp[i][i][0] = a[i];

    FOR(len, 2, n+1){
        REP(l,n-len+1){
            LL r = l + len - 1;
            LL vl = a[l] + dp[l+1][r][1];
            LL vr = a[r] + dp[l][r-1][1];
            if(vl > vr){
                dp[l][r][0] = vl;
                dp[l][r][1] = dp[l+1][r][0];
            }
            else {
                dp[l][r][0] = vr;
                dp[l][r][1] = dp[l][r-1][0];
            }
        }
    }
    PUTS(dp[0][n-1][0] - dp[0][n-1][1]);
}