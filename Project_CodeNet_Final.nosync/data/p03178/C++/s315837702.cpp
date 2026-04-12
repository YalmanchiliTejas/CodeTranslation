/**
    ▂▃▅▇█▓▒░۩۞۩ ۩۞۩░▒▓█▇▅▃▂
        Make it happen now, not tomorrow.
        Tomorrow is a  loser's excuse.
    ▂▃▅▇█▓▒░۩۞۩ ۩۞۩░▒▓█▇▅▃▂
**/
#ifndef _GLIbCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplu >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <cstring>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include<random>
#include <chrono>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplu >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
#endif
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
// #define INF 0x7f7f7f7f
#define ull unsigned long long int
#define pii pair<int,int>
#define ll long long int
#define ld long double
#define MSET(x,y) memset(x,y,sizeof(x))
// #define l long
#define se second
#define fi first
#define NIL 0
#define UNVISITED -1
#define EXPOLORED 0
#define mk make_pair
#define pb push_back
#define sc(n) scanf("%d",&n)
#define NIL 0
#define pii pair<int,int>
#define eps 1e-8
#define all(x) x.begin(),x.end()
#define me(u,v,w) make_pair(w,make_pair(u,v))
#define sqr(x) x*x
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define inrange(x,y,row,col) (x>=0 && y>=0 && x<row && y<col)
#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++ e)
// #define add(a,b) (a + b >= MOD ? a+b-MOD:a+b)
#define hs(c1,c2) (256*min(c1,c2) + max(c1,c2))
typedef struct{ int sum,suf,pre,max;} Node;
int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
const int MAXN = 3010;
const int UP = 31;
// const ll inf = 1e18;
const int mod = 1e9+7;
const ll highest = 1e18;
// const int inf = 1e9+10;
// const double pi = 3.141592653589793238462643383;
const double pi = acos(-1);
const double Phi =  1.618033988749894;
const int logn = 20;
const double phi = 0.618033988749894;
const double root5 = 2.236067977;
const int N = 1e5+10;
/**
    ▂▃▅▇█▓▒░۩۞۩ ۩۞۩░▒▓█▇▅▃▂
        Make it happen now, not tomorrow.
        Tomorrow is a loser's excuse.
    ▂▃▅▇█▓▒░۩۞۩ ۩۞۩░▒▓█▇▅▃▂
**/
char k[N];
void add_self(int &a,int b){
    a += b;
    if(a >= mod)a -= mod;
}
int main(){
    scanf("%s",k);
    int D;
    scanf("%d",&D);
    int len = strlen(k);
    std::vector<std::vector<int> > dp(D,std::vector<int>(2));
    //dp[sum][sm_already] - the number of ways to choose digits having sum % d = sum
    //such that sm_already says we have chosen a digit which is already smaller than k
    dp[0][0] = 1;
    for(int where=0;where<len;++where){
        std::vector<std::vector<int> > new_dp(D,std::vector<int> (2));
        for(int sum = 0;sum<D;++sum){
            for(int sm_al = 0;sm_al<2;++sm_al){
                for(int digit=0;digit<10;++digit){
                    if(digit>k[where]-'0' && !sm_al){
                        break;
                    }
                    add_self(new_dp[(sum+digit)%D][sm_al || (digit<k[where] - '0')],dp[sum][sm_al]);
                }
            }
        }
        dp = new_dp;
    }
    int ans = (dp[0][false] + dp[0][true])%mod;
    ans -= 1;
    if(ans==-1){
        ans = mod-1;
    }
    cout<<ans<<endl;
    return 0;
}