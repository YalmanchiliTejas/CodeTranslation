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

LL dp[105][5] = {{0}};
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    LL k;
    cin>>s>>k;

    LL sz = SZ(s);
    LL zero = 0;
    REP(i,sz){
        LL keta = sz-i; // 100 -> 3
        LL x = s[i] - '0';
        dp[i][0] = 0;
        //dp[i][1] = 9*(keta-1) + x;
        //dp[i][2] = 9*9*(keta-1)C2 + x * 9*(keta-1);
        //dp[i][3] = 9*9*9*(keta-1)C3 + x * 9*9*(keta-1)C2;
        if(x == 0){
            zero++;
            dp[i][1] = 0;
            dp[i][2] = 0;
            dp[i][3] = 0;
            if(i != 0) {
                dp[i][1] += dp[i-1][1];
                dp[i][2] += dp[i-1][2];
                dp[i][3] += dp[i-1][3];
            }
            continue;
        }
        
        if(i == 0) {
            dp[i][1] = 9*(keta-1) + x;
            if(keta >= 2){
                dp[i][2] = 81*(keta-1)*(keta-2)/2 + (x-1) * 9*(keta-1);
            }
            else {
                dp[i][2] = 0;
            }
            if(keta >= 3){
                dp[i][3] = 9*9*9*(keta-1)*(keta-2)*(keta-3)/6 + (x-1)*81*(keta-1)*(keta-2)/2;
            }
            else {
                dp[i][3] = 0;
            }
        }
        if(i-zero == 1) {
            dp[i][1] = 0;
            dp[i][2] = 9*(keta-1) + x;
            if(keta >= 2){
                dp[i][3] = 81*(keta-1)*(keta-2)/2 + (x-1) * 9*(keta-1);
            }
            else {
                dp[i][3] = 0;
            }
        }
        if(i-zero == 2) {
            dp[i][1] = 0;
            dp[i][2] = 0;
            dp[i][3] = 9*(keta-1) + x;
        }
        if(i != 0) {
            dp[i][1] += dp[i-1][1];
            dp[i][2] += dp[i-1][2];
            dp[i][3] += dp[i-1][3];
        }
        //cout<< dp[i][1] <<","<< dp[i][2] <<","<< dp[i][3] << endl;
    }
    PUTS(dp[sz-1][k]);
}