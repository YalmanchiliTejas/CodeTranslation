//main関数は一番下にあります

#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
#define srep(i, j, k) for (int i = j; i < k; i++)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vi2 = vector<vi>;
using vl2 = vector<vll>;
using vb = vector<bool>;
using S = string;
using vs = vector<string>;
using P = pair<int, int>;
using vp = vector<P>;
using vb = vector<bool>;
using ull = unsigned long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1001001001;

//mint用の定数 (10の9乗 + 7)
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

struct combination {
    vector<mint> fact, ifact;
    combination(int n) :fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
    mint p(int n, int k) {
        return fact[n] * ifact[n - k];
    }
} c(1000005);

struct UF {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;

    UF(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }
};

//エラトステネスの篩
vector<int> sosuu(100001);
vector<int> estora(vector<int> num) {
    int sel = 0;
    while (sel < num.size()) {
        int d = num[sel];
        for (int i = 0; i < num.size(); i++) {
            if (num[i] % d == 0 && num[i] != d && d != 1) {
                num.erase(num.begin() + i);
                i--;
            }
        }
        sel++;
    }
    rep(i, num.size()) {
        sosuu[num[i]] = 1;
    }
    return num;
}
/*ライブラリ最大公約数*/
//ユーグリッドの互除法
int gcd(int x, int y) {
    int num[3];
    num[0] = (x > y) ? x : y;
    num[1] = (x <= y) ? x : y;
    num[2] = num[0] % num[1];

    while (num[2]) {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] % num[1];
    }

    return num[1];
}

/*素因数分解*/
//自作ライブラリ
//iを常に素数にしておかないとうまくできない&&計算量ヤバイ
//エストラネスの篩で素数を振るっておく必要性がありそう
vector<P> fac(ll n, ll youso) {
ll ans = 1;
    ll kazu = n;
    vector<P> num(0);
    for (int i = 2; i <= sqrt(n); i++) {
        P kari;
        kari.first = i;
        int kai = 0;
        while (1) {
            if (kazu % i != 0) break;

            kazu /= i;
            kari.second++;
            kai++;
        }
        ans *= pow(i, kai / youso);
        if (kari.second != 0)
            num.emplace_back(kari);
    }
    if (n != 1)
        num.emplace_back(P(kazu, 1));
    return num;
    /*int ans = 0;
    if (kazu != 1) ans++;
    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = 1; j <= num[i]; j++) {
            num[i] -= j;
            ans++;
        }
    }*/
    return num;
}

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

mint pow_kai(int a, int n) {//aのn乗を計算します。
    mint x = 1;
    while (n > 0) {//全てのbitが捨てられるまで。
        if (n & 1) {//1番右のbitが1のとき。
            x = x * a;
        }
        a = a * a;
        n >>= 1;//bit全体を右に1つシフトして一番右を捨てる。
    }
    return x;
}

mint chooes(int n, int a) {
    mint x = 1, y = 1;
    rep(i, a) {
        x *= n - i;
        y *= i + 1;
    }
    return x / y;
}

int main() {
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    int ans = INF;
    int kari = 0;
    int num1 = a + b;
    int num2 = 2 * c;
    int mai = min(x, y);
    if (num1 <= num2) {
        kari = num1 * mai;
    }
    else {
        kari = num2 * mai;
    }
    x -= mai;
    y -= mai;
    if (x > 0)
        kari += min(a, 2 * c) * x;
    else
        kari += min(b, 2 * c) * y;
    cout << kari << endl;
    return 0;
}