#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(int i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(int i = (a); i >= (b); --i)   // 終端を0じゃなくて、1まですることによってn回。感覚的に1以上にしておいた。
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)

#define DEBUG_VARIABLE(variable) cout << #variable << ":" << variable << endl

#define INFTY (1 << 21) //10^21
#define INF (1 << 9)

#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない

#define N 100
int M[N][N];// 隣接行列(頂点と頂点が繋がってる、もしくは重みの値)
int color[N]; // その頂点の探索具合

const int TABLEMAX = 510000;
const int MOD = 1000000007;
//二項係数用の各階乗の値とその逆元を記録するための配列．
long long fac[TABLEMAX], finv[TABLEMAX], inv[TABLEMAX];

//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
static const int NIL = -1;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef vector<pair<ll, ll>> Vec_map;
//因数分解で使う。firstは数。secondは指数。
vector<pair<ll, ll>> prime_factor;
//因数の一覧を取得で使う
Vector factor_list;

ll n;

template <class X> void printArray(X *array, ll);
template <class X> void printVector(vector<X> &v);
template <class X> void printDimention(vector<vector<X>> &dv);
template <class X> void printMap(X);
template <class X> void printVecPair(vector<X> &v);
// 何個2がかかっているか
ll factor2(ll);
//nCr方式で組み合わせの数を求める
ll combination(int, int);
//nPrで階乗を求める
int factorial(int, int);
//桁数を返す
int find_digits(int);
// 各桁の和を計算する関数
int findSumOfDigits(int);
//次数を得る
int degree(int);
//四捨五入
int shishagonyu(double);
//切り上げ
int roundUp(double);
//切り捨て
int roundDown(double);
//四捨五入
int roundOff(double);
//最大公約数(Greatest Common Divisor)
int gcd (int, int);
//最小公倍数(Least Common Multiple)
ll lcm(ll, ll);
//素因数分解
void prime_factorization(ll);
//エラトステネスの篩
int Eratosthenes(int);
//偶奇判定。奇数ならtrue。
bool odd_even(int);
//aのmod mにおける逆元を計算する
long long modinv(long long, long long);
// a^n mod を計算する（二分累乗）
long long modpow(long long, long long, long long);
//テーブルを作る前処理
void COMinit();
//二項係数計算 nCk, 1 <= k <= n <= 10^7
long long COM(int, int);
// longlong型で絶対値を帰す。
long long abs_ll(ll);
// 割り算した時に余りが有る時だけ、+1の商を返す。
long long div_one(ll, ll);
// Stringの各桁をvectorの配列に入れる。でかい桁が添字0。
template <class X> void StringtoVec(string, vector<X> &v);
// 因数の一覧を取得する
void get_factor_list(ll);

// Barger, Pattey
vector<pair<ll, ll>> barger;

// 返す値はパティの数。引数はバーガーのレベルと左から何枚目かを表す
ll pattey(ll level, ll x){
    ll center = (barger[level].first / 2) + 1;
    // DEBUG_VARIABLE(level);
    // DEBUG_VARIABLE(x);
    // DEBUG_VARIABLE(center);
    // cout << endl;

    if(level == 0)  return 1;
    else if(x == 1) return 0;
    else if(x < center) return pattey(level - 1, x - 1);
    else if(x == center)    return barger[level - 1].second + 1;
    else if(x < barger[level].first)    return barger[level - 1].second + 1 + pattey(level - 1, x - center);
    else    return barger[level].second;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x;
    cin >> n >> x;

    barger.push_back(make_pair(1, 1));
    FOR_EQ(i, 1, n){
        barger.push_back(make_pair(3 + 2 * barger[i - 1].first, 1 +  2 * barger[i - 1].second));
    }
    // printVecPair(barger);

    ll res = pattey(n, x);


    cout << res << endl;

    return 0;
}

template<class X> void printArray(X array[], ll n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

template<class X> void printVector(vector<X> &v){
    rep(i, (int)v.size()){
        if(i)   cout << " ";
        cout << v[i];
    }
    cout << endl;
}

//二次元配列の表示
template<class X> void printDimention(vector<vector<X>> &dv){
    rep(i, (ll)dv.size()){
        rep(j, (ll)dv[i].size()){
            if(j)   cout << " ";
            cout << dv[i][j];
        }
        cout << endl;
    }
}

//mapの表示
template <class X> void printMap(X mp) {
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}

// 内部にpairを内包したvectorの表示
template <class X> void printVecPair(vector<X> &v){
    rep(i, (int)v.size()){
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

//numの中に何個2がかかってるか
ll factor2(ll num){
    int cnt = 0;
    while(num % 2 == 0){
        num /= 2;
        cnt++;
    }
    return cnt;
}

//nCr方式で組み合わせの数を求める
ll combination(int n, int r){
    ll up = 1, down = 1;
    // 以下2行はお試し
    ll half = n / 2;
    if(r >= half)   r = n - r;
    ll up_tmp = n, down_tmp = r;

    if(r == 0)  return 1;
    rep(i, r){
        up *= up_tmp;
        up_tmp--;
        down *= down_tmp;
        down_tmp--;
    }

    return up/down;
}



//nPr方式で階乗を求める
int factorial(int n, int r){
    if(n < r){
        cout << "error" << endl;
        return 0;
    }else{
        int res = 1;
        while(r){
            r--;
            res *= n;
            n--;
        }
        return res;
    }
}

//桁数を返す
int find_digits(int n){
    int digit = 0;

    while(n){
        n /= 10;
        digit++;
    }
    return digit;
}
// 各桁の和を計算する関数
int findSumOfDigits(int n){
    int sum = 0;
    while (n > 0) { // n が 0 になるまで
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
//次数を得る
int degree(int n){
    int count = 0;
    while(1){
        if(count <= 0)  break;
        count /= 2;
        count++;
    }
    return count;
}

//四捨五入
int shishagonyu( double x )
{
    return (int)( x < 0.0 ? x-0.5 : x+0.5 );
}

//切り上げ
int roundUp(double n){
    if(n >= 0){
        return (int)n + 1;
    }else{
        return (int)n - 1;
    }
}

//切り捨て
int roundDown(double n){
    return (int)n;
}

//四捨五入
int roundOff(double n){
    double decimal = 0;

    decimal = n - (int)n;

    if(decimal >= 0.5 || decimal <= -0.5){
        return roundUp(n);
    }else{
        return roundDown(n);
    }
}

//最大公約数(Greatest Common Divisor)
int gcd (int m, int n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;
    
    //ユークリッドの互除法
    while(m != n){
        if(m > n)   m = m - n;
        else    n = n - m;
    }
    return m;
}

//最小公倍数(Least Common Multiple)
ll lcm(ll m, ll n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;
    
    //lcm = m * n / gcd(m, n)
    return ((m / gcd(m, n)) * n);
}

//素因数分解 firstは数。secondは指数。
void prime_factorization(ll n){
    int a = 2, res;
    
    bool flg = false;
    if(n < 2){
        cout << "Error" << endl;
        return;
    }
    while(n >= a * a){
        if(n % a == 0){
            res = a;
            //resをグローバルな配列に代入すれば記録できる。
            if(flg){
                prime_factor[prime_factor.size() - 1].second++;
            }else{
                prime_factor.push_back(make_pair(0, 1));
                prime_factor[prime_factor.size() - 1].first = res;
            }
            n /= a;
            flg = true;
        }else{
            a++;
            flg = false;
        }
    }
    //ラス1の素因数
    res = n;
    if(prime_factor[prime_factor.size() - 1].first == res){
        prime_factor[prime_factor.size() - 1].second++;
    }else{
        prime_factor.push_back(make_pair(res, 1));
    }
}

//エラトステネスの篩
int Eratosthenes(int n){
    bool prime[n];
    //prime[0]が1、prime[n - 1]がn。
    rep(i, n)   prime[i] = true;
    
    for(int i = 2; i < sqrt(n); i++){
        if(prime[i]){
            for(int j = 0; i * (j + 2) < n; j++){
                prime[i *(j + 2)] = false;
            }
        }
    }

    int cnt = 0;
    for(int i = 2; i < n; i++){
        if(prime[i]){
            cnt++;
        }
    }
    return cnt;
}
//偶奇判定。奇数ならtrue。
bool odd_even(int num){
    bool judge;
    if(num % 2){
        judge = true;
    }else{
        judge = false;
    }
    return judge;
}
//aのmod mにおける逆元を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//main関数内でCOMinitを呼んだ後，COMを呼ぶ．
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < TABLEMAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算 nCk, nCrのcombinationでも使える
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long abs_ll(ll a){
    if(a >= 0){
        return a;
    }else{
        return -a;
    }
}

// 割り算した時に余りが有る時だけ、+1の商を返す。
long long div_one(ll res, ll div){
    // res 割られる数、div 割る数
    return (res + div - 1)/div;
}

// Stringの各桁をvectorの配列に入れる。でかい桁が添字0。
template <class X> void StringtoVec(string str, vector<X> &v){
    ll num = stoll(str);
    ll it = str.size() - 1;
    // 桁を逆にしたい時、下をon
    //ll it = 0;
    v.resize(str.size());
    while(num){
        v[it] = num % 10;
        num /= 10;
        it--;
        //it++;
        if(it < 0){
            cout << "reference error" << endl;
            break;
        }
    }
}

// nに数を入れるとその約数の一覧をfactor_listに格納する
void get_factor_list(ll n){
    int a = 1, res;

    while(n >= a * a){
        if(n % a == 0){
            res = a;
            ll tmp = n / res;
            factor_list.push_back(res);
            factor_list.push_back(tmp);
            a++;
        }else{
            a++;
        }
    }
    sort(factor_list.begin(), factor_list.end());
}