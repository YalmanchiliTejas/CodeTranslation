#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(int i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(int i = (a); i > (b); --i)
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)

#define DEBUG_VARIABLE(variable) cout << #variable << ":" << variable << endl

#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない
#define N 100
#define INFTY (1 << 21) //10^21
#define INF (1 << 9)
int M[N][N];//隣接行列
int color[N];
const int TABLEMAX = 510000;
const int MOD = 1000000007;
//二項係数用の各階乗の値とその逆元を記録するための配列．

//long long fac[TABLEMAX], finv[TABLEMAX], inv[TABLEMAX];

//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
static const int NIL = -1;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector>	DVector;
//因数分解で使う
Vector factor;
Vector factor_num;
ll n;

void printArray(int *array, int);
void printVector(Vector &v);
void printDimention(DVector &dv);
// 何個2がかかっているか
int factor2(int);
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
int lcm(int, int);
//素因数分解
void prime_factorization(int);
//エラトステネスの篩
int Eratosthenes(int);
//偶奇判定。奇数ならtrue。
bool odd_even(int);
//aのmod mにおける逆元を計算する
long long modinv(long long, long long);
// a^n mod を計算する（二分累乗）
long long modpow(long long, long long, long long);
/*
//テーブルを作る前処理
void COMinit();
//二項係数計算 nCk
long long COM(int, int);
*/

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    int h[n];
    rep(i, n){
        cin >> h[i];
    }
    int cnt = 1;
    
    for(int i = n - 1; i >= 1; i--){
        bool flg = 1;
        for(int j = i - 1; j >= 0; j--){
            if(h[j] > h[i]){
                flg = 0;
                break;
            }
        }
        if(flg){
            //DEBUG_VARIABLE(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}

//配列の表示．array[]の型を変えれば対応可能．
void printArray(int array[], int n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

//Vectorの表示．Vectorの型を変えれば対応可能．vector<???>
void printVector(Vector &v){
    rep(i, (int)v.size()){
        if(i)   cout << " ";
        cout << v[i];
    }
    cout << endl;
}

//二次元配列の表示
void printDimention(DVector &dv){
    rep(i, (int)dv.size()){
        rep(j, (int)dv[i].size()){
            if(j)   cout << " ";
            cout << dv[i][j];
        }
        cout << endl;
    }
}

//numの中に何個2がかかってるか
int factor2(int num){
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
    ll up_tmp = n, down_tmp = r;

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
int lcm(int m, int n){
    //引数に0がある場合は0を返す
    if(m == 0 || n == 0)    return 0;
    
    //lcm = m * n / gcd(m, n)
    return ((m / gcd(m, n)) * n);
}

//素因数分解
void prime_factorization(int n){
    int a = 2, res;
    
    bool flg = false;
    while(n >= a * a){
        if(n % a == 0){
            res = a;
            //resをグローバルな配列に代入すれば記録できる。
            if(flg){
                factor_num[factor.size() - 1]++;
            }else{
                factor.push_back(0);
                factor_num.push_back(1);
                factor[factor.size() - 1] = res;
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
    if(factor[factor.size() - 1] == res){
        factor_num[factor.size() - 1]++;
    }else{
        factor.push_back(res);
        factor_num.push_back(1);
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
/*
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算 nCk
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
*/