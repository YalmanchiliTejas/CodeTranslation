#pragma region
//gcc
//#include <bits/stdc++.h>
//clang
#include <set>      //******************************************************* *
#include <map>      //* *****          **                    *    **          *
#include <list>     //*       ******** ****** ******* ** ******** * ** * **** *
#include <queue>    //** ******      *            *   ** ***** ** *  * * ** * *
#include <stack>    //**     *** *** * ****** ** ****  * **         ** *  * * *
#include <cmath>    //** *** ******* *   *  * **** ***** ** **** ** ** **** * *
#include <ctime>    //** ***       * ***** ** * *  *     ** ******* **      * *
#include <cstdio>   //** ********* *        * ******* ****        * ******* * *
#include <vector>   //**      ** * * ****** * ** * *  * ** *** ** * ******* * *
#include <string>   //** ****  * * ******** * *  * ** *    *   ****         * *
#include <bitset>   //** **  * * *        *   **** ************************** *
#include <cctype>   //**   * * * ****** * ***            *                    *
#include <cstdlib>  //**** *   *        ** ****** ******** ********* **********
#include <cstring>  //**** ************ **    * * ******** *         *        *
#include <utility>  //*         * ************* *          ********* * ****** *
#include <numeric>  //* ******* * *       **    * ******** *****   * *      * *
#include <complex>  //* * *     * * ***** *  * ** *   ******   * * * ****** * *
#include <sstream>  //* * ***** * *   * * * ** ** * * ******** * **  ****** * *
#include <fstream>  //* *     * * * * * * * ** **** *          *    **      * *
#include <iomanip>  //* * *** *** * * *   * ** **** * ******** ************ * *
#include <cassert>  //*   * *     * * * *   **    * *     *******         * * *
#include <iostream> //* *** *** ***** * ********* * ***** **      ********* * *
#include <iterator> //* *             *         *   *****    ****           * 
#include <algorithm>//*********************************************************

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

const char alphabetl[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                            'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                            'u', 'v', 'w', 'x', 'y', 'z'};
const char alphabetu[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                            'U', 'V', 'W', 'X', 'Y', 'Z'};
const double pi     = 3.141592653589793238462643383279502884197169;
const double napier = 2.718281828459045235360287471352662497757247;
static const double EPS = 1e-14;
static const ll INFLL = 1e18;
static const int INF = (1 << 30) - 1;
static const ll MOD = (ll) 1e9 + 7;
const int NM = 10100;//max index of array

#define cauto const auto&
#define bit(n) (1LL<<(n))
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define itn int

#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define INF(a) memset(a, 0x3f, sizeof(a))

#define FILL(a,c) fill(a, a+ sizeof(a)/sizeof(*a),c)
#define FILL2D(A,c) fill(A[0], A[0] +sizeof(A)/sizeof(**A),c)
#define FILL3D(A,c) fill(A[0][0], A[0][0] +sizeof(A)/sizeof(***A),c)

#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define reps(i,n) for(int i=0; i<=(int)(n); i++)
#define rrep(i,n) for(int i=(n-1); i>=0; i--)
#define rreps(i,n) for(int i=(n); i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<(int)(b); i++)
#define FOREQ(i,a,b) for(int i=a; i<=(int)(b); i++)
#define RFOR(i,a,b) for(int i=a; i>(int)(b); i--)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)

#define ALL(x) (x).begin(),(x).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()

#define PRINT(n) cout << n << "\n";
#define PRINT2(n, m) cout << n << " " << m << " "<< "\n";

#define IN(a, x, b) (a<=x && x<b)
#define pb push_back

template<class T1, class T2>
bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2>
bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }


const ll MAX_V = 1010;
const ll MAX_E = 2010;
ll V, E;
struct edge {
    ll from;
    ll to;
    ll cost;
};
edge ES[MAX_E];
ll d[MAX_V];


class range {
private: struct I {
            int x;
            int operator*(){ return x; }
            bool operator!=(I& lhs){ return x<lhs.x; }
            void operator++(){ ++x; }
        };
        I i,n;
public:
    range(int n) : i({0}), n({n}) { }
    range(int i,int n) : i({i}), n({n}) { }
    I& begin() { return i; }
    I& end()   { return n; }
};


int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/** example
popCount(5)    = 2 (5    = 0b101 -> 2)
popCount(2133) = 5 (2133 = 0b100001010101 -> 5)
**/
int popCount(unsigned int data){
    data = (data & 0x55555555)
        + ((data & 0xAAAAAAAA) >> 1);
    data = (data & 0x33333333)
        + ((data & 0xCCCCCCCC) >> 2);
    data = (data & 0x0F0F0F0F)
        + ((data & 0xF0F0F0F0) >> 4);
    data = (data & 0x00FF00FF)
        + ((data & 0xFF00FF00) >> 8);
    data = (data & 0x0000FFFF)
        + ((data & 0xFFFF0000) >> 16);
    return data;
}

/** example
bitReverse(0b01011001) = 0b10011010
**/
unsigned int bitReverse(unsigned int data){
    data = ((data & 0x55555555) << 1)
        |  ((data & 0xAA555555) >> 1);
    data = ((data & 0x33333333) << 2)
        |  ((data & 0xCCCCCCCC) >> 2);
    data = ((data & 0x0F0F0F0F) << 4)
        |  ((data & 0xF0F0F0F0) >> 4);
    data = ((data & 0x00FF00FF) << 8)
        |  ((data & 0xFF00FF00) >> 8);
    data = (data << 16) | (data >> 16);
    return data;
}

/** example
showElem(5, 2340182213LL) === false
showElem(8, 8327237484LL) === true
**/
bool showElem(int n, ll target) {
    if (9 < n) {
        return false;
    }
    string s = to_string(target);
    bool is = false;
    for(int i = 0; i < SZ(s); i++) {
        if (s[i] == char(n + '0')){
            is = true;
            break;
        }
    }
    return is;
}

/** example
sumMapDigitToIntShow(83242LL)       = 19LL
sumMapDigitToIntShow(12312445287LL) = 40LL
**/
ll sumMapDigitToIntShow(ll target){
    ll dig, sum = 0;
    while(target) {
        dig = target % 10;
        sum += dig;
        target /= 10;
    }
    return sum;
}

void precalc() {
    /*
    for (int i = 2; i < C; ++i) {
        if (!least_prime[i]) {
            least_prime[i] = i;
            for (li j = i * 1LL * i; j < C; j += i) {
                least_prime[j] = i;
            }
        }
    }
    */
    /*
    fact[0] = revfact[0] = 1;
    for (int i = 1; i < 100500; ++i) {
        fact[i] = fact[i - 1] * i % curMod;
        revfact[i] = binpow(fact[i], curMod - 2, curMod);
    }
    */
    /*
    for (int w = 0; w < 2; ++w) {
        powers[w][0] = 1;
        for (int j = 1; j < C; ++j) {
            powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
        }
    }
    */
    /*
    catalan[0] = 1;
    for (int n = 0; n < 200500 - 1; ++n) {
        catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD
                            * binpow(n + 2, MOD - 2, MOD) % MOD;
    }
    */
    /*
    for (int i = 0; i < 5010; ++i) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
    */
    /*
    for (int i = 0; i < 100; ++i) {
        doubleC[i][i] = doubleC[i][0] = 1.0;
        for (int j = 1; j < i; ++j) {
            doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
        }
    }
    */
}
void Main();
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

#pragma endregion

/***
 *  AtCoder tenka1_2019_b
 *  2019/09/02 GeckoCPPSonata
 ***/
void Main(){
    // Write your source code Here...
    int N;
    string s;
    int K;
    cin >> N >> s >> K;
    char c = s[K-1];
    REP(i,N){
        if (s[i] != c) s[i] = '*';
    }
    PRINT(s)
}
