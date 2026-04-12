#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i, s, n) for(int i = (s), i##_len=(n); i < i##_len; ++i)
#define FORS(i, s, n) for(int i = (s), i##_len=(n); i <= i##_len; ++i)
#define VFOR(i, s, n) for(int i = (s); i < (n); ++i)
#define VFORS(i, s, n) for(int i = (s); i <= (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define REPS(i, n) FORS(i, 0, n)
#define VREP(i, n) VFOR(i, 0, n)
#define VREPS(i, n) VFORS(i, 0, n)
#define RFOR(i, s, n) for(int i = (s), i##_len=(n); i >= i##_len; --i)
#define RFORS(i, s, n) for(int i = (s), i##_len=(n); i > i##_len; --i)
#define RREP(i, n) RFOR(i, n, 0)
#define RREPS(i, n) RFORS(i, n, 0)
#define LLFOR(i, s, n) for(ll i = (s), i##_len=(n); i < i##_len; ++i)
#define LLFORS(i, s, n) for(ll i = (s), i##_len=(n); i <= i##_len; ++i)
#define LLVFOR(i, s, n) for(ll i = (s); i < (n); ++i)
#define LLVFORS(i, s, n) for(ll i = (s); i <= (n); ++i)
#define LLREP(i, n) LLFOR(i, 0, n)
#define LLREPS(i, n) LLFORS(i, 0, n)
#define LLVREP(i, n) LLVFOR(i, 0, n)
#define LLVREPS(i, n) LLVFORS(i, 0, n)
#define LLRFOR(i, s, n) for(ll i = (s). i##_len=(n); i >= i##_len; --i)
#define LLRFORS(i, s, n) for(ll i = (s), i##_len=(n); i > i##_len; --i)
#define LLRREP(i, n) LLRFOR(i, n, 0)
#define LLRREPS(i, n) LLRFORS(i, n, 0)
#define IREP(i, v) for(auto i = (v).begin(); i != (v).end(); ++i)
#define IRREP(i, v) for(auto i = (v).rbegin(); i != (v).rend(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define SZ(x) ((int)(x).size())
#define REV(x) reverse(ALL(x))
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define MT make_tuple
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())

using ld = long double;
using ll = long long;
using ui = unsigned int;
using ull = unsigned long long;
using Pi_i = pair<int, int>;
using Pll_ll = pair<ll, ll>;
using VB = vector<bool>;
using VC = vector<char>;
using VD = vector<double>;
using VI = vector<int>;
using VLL = vector<ll>;
using VS = vector<string>;
using VSH = vector<short>;
using VULL = vector<ull>;

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const ll LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}




 
 
int main(){
    int N; cin >> N;
    if(!(N % 2)){
        VI A(N);
        VLL sumO(N/2 + 1,0), sumE(N/2 + 1,0);
        REP(i, N){
            cin >> A[i];
            if(i % 2) sumO[(i+1)/2] = sumO[(i+1)/2 - 1] + A[i];
            else sumE[i/2 + 1] = sumE[i/2] + A[i];
        }
        ll ans(max(sumE[N/2], sumO[N/2]));
        FORS(i, 0, N/2){
            chmax(ans, sumO[N/2] - sumO[i] + sumE[i]);
        }
        cout << ans << endl;
    }else{
        VLL sumE(N/2 + 2, 0), sumO(N/2 + 1, 0);
        VI A(N);
        REP(i, N){
            cin >> A[i];
            if(i % 2) sumO[(i+1)/2] = sumO[(i+1)/2 - 1] + A[i];
            else sumE[i/2 + 1] = sumE[i/2] + A[i];
        }
        ll ans(sumO[N/2]);
        for(int i = 0; i < N; i += 2){
            chmax(ans, sumE[N/2 + 1] - A[i]);
        }
        for(int i = 2; i <= N/2 + 2; ++i){
            chmax(ans, sumE[N/2 + 1] - sumE[i-1] + sumO[i-2]);
        }
        for(int i = 1; i <= N/2 + 1; ++i){
            chmax(ans, sumO[N/2] - sumO[i-1] + sumE[i-1]);
        }
        VLL dp(N/2 + 2, 0);
        if(N > 6){
            dp[4] = A[0] + A[3];
            FORS(i, 5, N/2 + 1)
                dp[i] = max(dp[i-1] , sumE[i-3]) + A[2*i-5];
        }
        for(int i =  4; i <= N/2 + 1; ++i){
            chmax(ans, dp[i] + sumE[N/2 + 1] - sumE[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}
