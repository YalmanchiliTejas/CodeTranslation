#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);
//=====================================================
// マクロ定義部　いつかヘッダファイルに分ける
//=====================================================
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(ll i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(ll i = (a)-1; i >= (b); --i)
// FOR_RE(i, n, n - m)  nからm回分
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)

#define DEBUG_VARIABLE(variable) cout << #variable << ":" << variable << endl

#define INFTY 1000000000000

#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない
//=====================================================
// 型定義部　いつかヘッダファイルに分ける
//=====================================================
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;
typedef vector< pair<ll, ll> > Vec_Pair;
//=====================================================
// 基本変数
//=====================================================
const int TABLEMAX = 510000;
const int MOD = 1000000007;
// 二項係数( nCk = n!/(k! * (n - k)!) )用の各階乗の値とその逆元を記録するための配列．
/**
 * fac: 分子、inv: 分母(逆元１つ)、finv: 逆元の累積値
 * オーバーフローなどで負の数になってしまうと、MOD 演算で狂いが生じるので、
 * unsigned にしてしまう
 */
unsigned long long fac[TABLEMAX], inv[TABLEMAX], finv[TABLEMAX];

/*
//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};    // dj
const int dy[4] = {-1, 0, 1, 0};    // di
static const int NIL = -1;
*/
/**
 * abc152-e参考
 * 以下の配列は素数判定（エラトステネス → 素因数分解）で使用する
 * isprime, min_factor の上限値は素因数分解対象の平方根
 */
Vector primes;          // 素数を格納
vector<bool> isprime;   // 素数かどうかを判定。isprime の添え字と見たい数は数値を一致させる（要素数をn + 1で確保）
Vector min_factor;      // min_factor[num] : numを割り切る最小の素数を格納
Vec_Pair res_pf;        // 素因数分解の結果を格納。first: 素因数、second: 指数
bool called_Eratosthenes = false;   // 既にエラトステネスの篩をやった
bool can_min_factor;     // 素因数分解対象が n <= 10^8 なので min_factor が使える

// 関数get_factor_listで使う。因数の一覧を取得で使う。
Vector factor_list;


//===================================================
// 関数のプロトタイプ宣言　いつかちゃんとヘッダファイルに分ける...
//===================================================
template <class X> void printArray(X *array, ll);
template <class X> void printVector(vector<X> &v);
template <class X> void printDimention(vector< vector<X> > &dv);
template <class X> void printMap(X);
template <class X> void printVecPair(vector<X> &v);
void printDV_Pair(vector<vector<pair<ll, ll> > > &v);
void printSet(set<ll> &S);
// 何個2がかかっているか
ll factor2(ll);
//nCr方式で組み合わせの数を求める
ll combination(ll, ll);
//nPrで階乗を求める
int factorial(int, int);
//桁数を返す
ll find_digits(ll);
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
ll gcd (ll, ll);
//最小公倍数(Least Common Multiple)
ll lcm(ll, ll);

//エラトステネスの篩
void Eratosthenes(ll);
//素因数分解
void prime_factorization(ll, ll);

//偶奇判定。奇数ならtrue。
bool odd_even(int);
// longlong型で絶対値を帰す。
long long abs_ll(ll);
// 割り算した時に余りが有る時だけ、+1の商を返す。
long long div_one(ll, ll);
// Stringの各桁をvectorの配列に入れる。でかい桁が添字0。
template <class X> void StringtoVec(string, vector<X> &v);
// 因数の一覧を取得する
void get_factor_list(ll);
// 繰返し自乗法
ll RepeatSquaring(ll a, ll index);
//====================================================
/**
 * 逆元系
 * COMinit() -> COM() で簡単に二項係数（組み合わせ）が求められる
 * メモリ容量が足りない場合、繰返し自乗法を用いて求める(combination関数)
 */
// テーブルを作る前処理
void COMinit();
// 二項係数計算 nCk, 1 <= k <= n <= 10^5
long long COM(ll, ll);
// 二項係数の計算。内部で繰返し自乗法を使用
ll combination_MOD(ll n, ll r);
// 繰返し自乗法 MOD使用
ll RepeatSquaring_MOD(ll a, ll index, ll M);
//====================================================

//===================================================
// グローバル
//===================================================
ll n, N, k, K;

//===================================================
// 関数
//===================================================


//===================================================
// main 問題処理部
//===================================================
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    Vector stock;
    //stock.push_back(-1);

    ll color = 0;
    rep(i, N){
        ll A;
        cin >> A;
        Vector::iterator it = lower_bound(stock.begin(), stock.end(), A);
        // DEBUG_VARIABLE(A);
        if(it == stock.begin()){
            // cout << "it 添字 " << it - stock.begin() << endl;
            // printVector(stock);
            stock.insert(it, A);
            color++;
        }else{
            // cout << "it 添字 " << it - stock.begin() << endl;
            // printVector(stock);
            stock.insert(it, A);
            it = lower_bound(stock.begin(), stock.end(), A);    // insert とするとコードテストで iterator が狂ったため
            // cout << "it 添字 " << it - stock.begin() << endl;
            // printVector(stock);
            stock.erase(--it);
        }
        // printVector(stock);
        // cout << endl;
    }
    cout << color << endl;

    return 0;
}

//=====================================================
// 関数群 いつか別のCファイルに分ける
//=====================================================

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
template<class X> void printDimention(vector< vector<X> > &dv){
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

// 内部にVec_Pairを内包したvectorの表示
void printDV_Pair(vector<vector<pair<ll, ll> > > &v){
    rep(i, (int)v.size()){
        cout << i << endl;
        rep(j, (int)v[i].size()){
            cout << v[i][j].first << " " << v[i][j].second << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void printSet(set<ll> &S){
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        if(it != --S.end() ) cout << *it << " ";
        else    cout << *it << endl;
    }
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
ll combination(ll n, ll r){
    if(n == 0 || r == 0 || n < r)    return 0;
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
ll find_digits(ll n){
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
    while(n > 1){
        n /= 2;
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
ll gcd (ll a, ll b){
    return b ?  gcd(b, a % b) : a;
}
/*
ll gcd (ll m, ll n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;
    if(m == 1 || n == 1)    return 1;
    
    //ユークリッドの互除法
    while(m != n){
        if(m == 1 || n == 1)    return 1;

        if(m > n)   m = m - n;
        else    n = n - m;
    }
    return m;
}
*/

//最小公倍数(Least Common Multiple)
ll lcm(ll m, ll n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;
    
    //lcm = m * n / gcd(m, n)
    return ((m / gcd(m, n)) * n);
}

/**
 * @brief isprime, min_factor を設定する
 * @param lim 素因数分解対象の上限値
 * Vector primes           // 素数を格納（全ての数を見る余裕がない時に）
 * vector<bool> isprime    // 素数かどうかを判定。isprime の添え字と見たい数は数値を一致させる（要素数をn + 1で確保）
 * Vector min_factor       // min_factor[num] : numを割り切る最小の素数を格納
 * bool called_Eratosthenes = false;   // 既にエラトステネスの篩をやった
 * bool can_min_factor     // 素因数分解対象が n <= 10^8 なので min_factor が使える
 */
// 素因数分解を高速にやるためにエラトステネスの篩を活用する
// エラトステネスの篩
void Eratosthenes(ll lim){
    
    isprime.resize(lim + 1, true);    // 素数かどうかを判定。isprime の添え字と見たい数は数値を一致させる（要素数をlim + 1で確保）
    min_factor.resize(lim + 1, -1);   // min_factor[num] : numを割り切る最小の素数を格納
    
    isprime[0] = isprime[1] = false;
    min_factor[0] = 0, min_factor[1] = 1;
    // num を p = min_factor[num] で割れるだけ割る」というのを num = 1 となるまで繰り返す
    // num の添字分まで必要なので、回すループの上限は
    // min_factorが必要でない。 prime に素数の実態がなくてよい場合、
    // iの上限はsqrt(n)まで　素数かどうかの判定はisprimeで可能
    for(int i = 2; i <= lim; i++){   // 素数
        if(!isprime[i]) continue;
        primes.push_back(i);
        min_factor[i] = i;
        for(int j = i * 2; j <= lim; j += i){   // 素数の倍数を省く
            isprime[j] = false;
            if(min_factor[j] == -1) min_factor[j] = i;  // まだ格納されていなければ
        }
    }
}
/**
 * この関数の呼び出し元で以下のように使用する
 * vector< vector<pair<ll, ll>> >    map;
 * map[i] = prime_factorization(n)
 *
 * @brief num を素因数分解した結果を res_pf に格納する
 * @param num 素因数分解対象
 * @param lim 素因数分解対象の上限値（複数回呼ばれることを見越して）
 */
void prime_factorization(ll num, ll lim){

    if(lim <= pow(10, 8)) can_min_factor = true;
    else    can_min_factor = false;

    if(!called_Eratosthenes){
        if(can_min_factor){
            Eratosthenes(lim);
        }else{
            lim = sqrt(lim);    // min_factor が使えないので、sqrt(num) までを調べる方に切り替える
            Eratosthenes(lim);
        }
        called_Eratosthenes = true;
    }

    if(num < 2){
        // error処理
        cout << "Error: can't do prime_factorization" << endl;
        return;
    }
    res_pf.clear();
if(can_min_factor){
    // example
    // n = 120
    // min_factor[120] = 2 → 120 / 2 をし続ける → n = 15
    // min_factor[15] = 3 → 15 / 3 をし続ける → n = 5
    // min_factor[5] = 5 → 5 / 5 をし続ける → n = 1  終わり
    while(num != 1){
        int prime = min_factor[num];
        int cnt = 0;
        while(min_factor[num] == prime){
            num /= prime;
            cnt++;
        }
        res_pf.push_back(make_pair(prime, cnt));
    }
}else{
    // lim が 10^8 以上で min_factor が使用できないので、squrt上限で愚直に素因数分解
    // 小さい素数の方から割っていく
    bool composite_num = false; // 合成数：１より大きい自然数で素数でない数
    ll index = 0;
    while(num != 1 && index < primes.size()){
        int prime = primes[index];
        int cnt = 0;
        if(num % prime == 0){
            composite_num = true;
            num /= prime;
            cnt++;
        }else{
            index++;
            res_pf.push_back(make_pair(prime, cnt));
        }
    }
    if(!composite_num){
        cout << "num is composite_num: num = 1 * num" << endl;
        res_pf.push_back(make_pair(num, 1));
    }
}
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

/**
 * main関数内で COMinit を呼んだ後、COM を呼ぶ．
 * MOD 界における話。COM の返り値も MOD の余が返ってくる。
 * fac: 分子の累積、inv: 分母(逆元１つ)、finv: 逆元の累積値
 * fac と finv は順列だと思いましょう
 * MOD界においては a^-1 = a^(MOD - 2)
 */
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    // i は数を表す
    // fac[5] = 5!
    // inv[5] = 5 の MOD における逆元
    // finv[5]
    for (int i = 2; i < TABLEMAX; i++){
        fac[i] = (fac[i - 1] * i) % MOD;
        // 拡張ユークリッドで高速に計算
        inv[i] = MOD -  inv[MOD % i] * (MOD / i)  % MOD;
        finv[i] = (finv[i - 1] * inv[i]) % MOD;
    }
}
// 二項係数計算 nCk, nCrのcombinationでも使える
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    // finv[n - k] で 分子のいらない部分を相殺
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
    int div = 1, res;

    while(n >= div * div){
        if(n % div == 0){
            res = div;
            ll tmp = n / res;
            factor_list.push_back(res);
            if(tmp != 1)    factor_list.push_back(tmp);
            div++;
        }else{
            div++;
        }
    }
    sort(factor_list.begin(), factor_list.end());
}

// 簡単な繰返し自乗法
// 再帰を使いながら高速で 
// a: 基数, index: 指数, M: MOD
ll RepeatSquaring_MOD(ll a, ll index, ll M){
    // Nは基数、Pは指数、MはMOD
    if(index == 0)  return 1;
    if(index % 2 == 0){
        ll tmp = RepeatSquaring_MOD(a, index/2, M);
        return tmp * tmp % M;
    }else{
        return a * RepeatSquaring_MOD(a, index - 1, M) % M;
    }
}

ll RepeatSquaring(ll a, ll index){
    if(index == 0)  return  1;
    else if(index % 2 == 0){
        ll tmp = RepeatSquaring(a, index / 2);
        return tmp * tmp;
    }else{
        return a * RepeatSquaring(a, index - 1);
    }
}

ll combination_MOD(ll n, ll r){
    ll nume = 1, denom = 1;
    FOR_EQ(i, n - r + 1, n){
        nume = (nume * i) % MOD;
    }
    FOR_EQ(i, 1, r){
        denom = (denom * i) % MOD;
    }
    denom = RepeatSquaring_MOD(denom, MOD - 2, MOD);

    return (nume * denom) % MOD;
}