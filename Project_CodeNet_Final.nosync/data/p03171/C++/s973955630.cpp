#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <stack>
// #include <ctime>
// #include <iomanip>
// #include <cstdlib>
using namespace std;

/// ================================ Define Part ================================
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define mt make_tuple
#define itr iterator
#define rtr reverse_iterator
#define hashmap unordered_map
#define hashset unordered_set
#define eol '\n'
#define V1(_x_) vector<_x_>
#define V2(_x_) vector<V1(_x_)>
#define V3(_x_) vector<V2(_x_)>
#define V4(_x_) vector<V3(_x_)>
#define sz(_x_) int((_x_).size())
#define all(_x_) (_x_).begin() , (_x_).end()
#define rall(_x_) (_x_).rbegin(), (_x_).rend()
typedef      double   db  ; typedef unsigned    int   uint;
typedef long double   ldb ; typedef unsigned long long ull; typedef long long   ll    ; 
typedef map<int, int> mi  ; typedef pair<int, int> pi     ; typedef map<ll, ll> mll   ; typedef pair<ll, ll> pll   ; 
typedef set<int>      si  ; typedef set<pi>        spi    ; typedef set<ll>     sll   ; typedef set<pll>     spll  ;
typedef V1(string)    vs  ; typedef V2(string)     v2_s   ; typedef V3(string)  v3_s  ; typedef V4(string)   v4_s  ;
typedef V1(bool)      vb  ; typedef V2(bool)       v2_b   ; typedef V3(bool)    v3_b  ; typedef V4(bool)     v4_b  ;
typedef V1(int)       vi  ; typedef V2(int)        v2_i   ; typedef V3(int)     v3_i  ; typedef V4(int)      v4_i  ;
typedef V1(ll)        vll ; typedef V2(ll)         v2_ll  ; typedef V3(ll)      v3_ll ; typedef V4(ll)       v4_ll ;
typedef V1(pi)        vpi ; typedef V2(pi)         v2_pi  ; typedef V3(pi)      v3_pi ; typedef V4(pi)       v4_pi ;
typedef V1(pll)       vpll; typedef V2(pll)        v2_pll ; typedef V3(pll)     v3_pll; typedef V4(pll)      v4_pll;
/// ================================ Independent  Functions ================================
template<typename _T_> tuple<_T_,_T_,_T_> extgcd(_T_ _a_,_T_ _b_) { if (_a_ == 0) return make_tuple(_b_, 0, 1); _T_ _g_, _x_ ,_y_; tie(_g_, _x_, _y_) = extgcd(_b_ % _a_, _a_); return make_tuple(_g_, _y_ - _b_ / _a_ * _x_, _x_); }
template<typename _T_>             _T_       gcd(_T_ _a_,_T_ _b_) { if(!_a_)return _b_;if(!_b_)return _a_;if(_a_<0)_a_=-_a_;if(_b_<0)_b_=-_b_;_T_ shift=0;while(!((_a_|_b_)&1))_a_>>=1,_b_>>=1,++shift;while(!(_a_&1))_a_>>=1;do{while(!(_b_&1))_b_>>=1;if(_a_>_b_)swap(_a_,_b_);}while(_b_-=_a_);return _a_<<shift;}
template<typename _T_>             _T_       lcm(_T_ _a_,_T_ _b_) { return _a_ / gcd(_a_, _b_) * _b_; }
template<typename _T_> void    maximize(_T_ &_a_, _T_ _b_) {     if (_a_ < _b_)   _a_ = _b_; }
template<typename _T_> void    minimize(_T_ &_a_, _T_ _b_) {     if (_a_ > _b_)   _a_ = _b_; }
template<typename _T_> bool    max_able(_T_ &_a_, _T_ _b_) { return (_a_ < _b_) ? _a_ = _b_, true : false; }
template<typename _T_> bool    min_able(_T_ &_a_, _T_ _b_) { return (_a_ > _b_) ? _a_ = _b_, true : false; }
template<typename _T_> bool      getBit(_T_  _x_, int _b_)           { return   _T_(1) & (_x_ >> _b_); }
template<typename _T_> void      setBit(_T_ &_x_, int _b_)           { _x_ |=  (_T_(1) << _b_); }
template<typename _T_> void    resetBit(_T_ &_x_, int _b_)           { _x_ &= ~(_T_(1) << _b_); }
template<typename _T_> void     flipBit(_T_ &_x_, int _b_)           { _x_ ^=  (_T_(1) << _b_); }
template<typename _T_> void     makeBit(_T_ &_x_, int _b_, bool _v_) { _x_ ^=  (_T_(1) << _b_) & (-_v_ ^ _x_); }
template<typename _T_> void writeUnsign(_T_  _n_) { if (_n_ > 9) writeUnsign(_n_ / 10); putchar(_n_ % 10 + '0'); }
template<typename _T_> void writeSigned(_T_  _x_) { if (_x_ < 0) putchar('-'), _x_ = -_x_; writeUnsign(_x_);      }
template<typename _T_> void   getString(_T_ &_s_) {char __;while(__=getchar(),__==' '||__=='\n'||__=='\t');_s_.clear();_s_.pb(__);while(__=getchar(),__!=EOF&&__!=' '&&__!='\n'&&__!='\t')_s_.pb(__);}
template<typename _T_> void   getUnsign(_T_ &_n_) {char __;while(__=getchar(),__<'0'||__>'9');_n_=__-'0';while(__=getchar(),__>='0'&&__<='9')_n_=10*_n_+__-'0';}
template<typename _T_> void   getSigned(_T_ &_n_) {char __;while(__=getchar(),__!='-'&&(__<'0'||__>'9'));bool sign(__=='-');if(sign)__=getchar();_n_=__-'0';while(__=getchar(),__>='0'&&__<='9')_n_=10*_n_+__-'0';if(sign)_n_=-_n_;}
template<typename _T_,typename..._V_>  void getUnsign(_T_ &_t_, _V_&..._v_) { getUnsign(_t_); getUnsign(_v_...); }
template<typename _T_,typename..._V_>  void getSigned(_T_ &_t_, _V_&..._v_) { getSigned(_t_); getSigned(_v_...); }
int readInt()  { int _x_; return getSigned(_x_), _x_; }     uint readUINT() { uint _x_; return getUnsign(_x_), _x_; }
ll  readLong() { ll  _x_; return getSigned(_x_), _x_; }     ull  readULL()  { ull  _x_; return getUnsign(_x_), _x_; }
#define file_inp(_s_) freopen(_s_, "r", stdin)
#define file_out(_s_) freopen(_s_, "w", stdout)
void file(const string FILE = "Test") {
    freopen((FILE + ".INP").c_str(), "r", stdin);
    freopen((FILE + ".OUT").c_str(), "w", stdout);
}
/// ================================ Dependent  Functions ================================
const db oo = 0.1 / 0;
const db PI = acos(-1);
const ll LINF = (1LL << 60);
const int INF = (1 << 30);
const int LIM = (1 << 24);
const int MOD = 1e9 + 7;
const int BASE = 1e4;
const int DIGIT = 4;
const int MAXVAL = 1e6 + 500;
/// ================================ Main part ================================

int main()
{
    int n = readInt();

    int a[n];
    for (int i = 0; i < n; ++i)
        getUnsign(a[i]);

    vector<vector<ll> > dp(n, vll(n, -LINF));
    for (int L = n - 1; L >= 0; --L)
        for (int R = L; R < n; ++R)
            if (L == R)
                dp[L][R] = a[L];
            else 
                dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);

    cout << dp[0][n - 1];
    return 0;
}