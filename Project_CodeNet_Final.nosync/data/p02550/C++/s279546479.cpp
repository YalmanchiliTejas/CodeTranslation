#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <functional>
#include <list>

#define MOD (1000000000 + 7)

using namespace std;

typedef long long ll;
const int MAX = 3000000;

long long fac[MAX], finv[MAX], inv[MAX];

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

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}
// テーブルを作る前処理
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

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

map<ll,ll> prime;//素因数分解でそれぞれの素数がいくつ出てきたかを保存するmap

//O(√n)
//整列済み(mapはkeyで自動で整列される)
void prime_factorize(ll n){
    if(n<=1) return;
    ll l=sqrt(n);
   for(ll i=2;i<=(ll)(l);i++) { //
        if(n%i==0){
            prime_factorize(i);prime_factorize(ll(n/i));return;
        }
    }
    //mapでは存在しないkeyの場合も自動で構築される
    prime[n]++;return;
} 

// 約数列挙？
vector<ll> divisor;
void list_divisor(ll n) {
    divisor.clear();
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            divisor.push_back(i);
            if(i*i != n) divisor.push_back(n/i);
        }
    }
    sort(divisor.begin(), divisor.end());
}

vector<bool> Eratosthenes(ll N) {
    vector<bool> primes(N, true);
    vector<ll> ret;
    primes[0] = false;
    primes[1] = false;
    for (ll i=2; pow(i,2)<=N; i++) {
        if (primes[i]) {
            for(int j=2; i*j<=N; j++) primes[i*j] = false;
            ret.push_back(primes[i]);
        }
    }
    return primes;//ret;
}

template <typename T> bool next_combination(const T first, const T last, int k) {
    // ** Sample **
    // vector<int> v{1, 2, 3, 4, 5, 6, 7};
    // do {
    //     for (int i = 0; i < k; i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << "| ";
    //     for (int i = k; i < v.size(); i++) {
    //         cout << v[i] << " ";
    //     }
    //     cout << endl;
    // } while(next_combination(v.begin(), v.end(), k));

    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};
// auto compare = [](pair<ll, ll> a, pair<ll, ll> b) {
//     ll a_mp = get<1>(a);
//     ll b_mp = get<1>(b);
//     return a_mp < b_mp;
//     // if (a_mp != b_mp) return a_mp > b_mp;
//     // else return get<0>(a) > get<0>(b);
// };

int main() {
    ll N, X, M;
    cin >> N >> X >> M;

    vector<ll> count(M, 0);

    ll now = X % M;
    ll sum = X % M;
    count[now]++;

    ll loop_start, loop_end = 0;
    ll loop_start_value = 0;

    bool first = false;

    for(ll i = 1; i < N; i++) {
        now = (now*now) % M;
        // cout << now << endl;
        if(count[now] == 1 && !first) {
            // cout << "start" << i << endl;
            first = true;
            loop_start = i;
            loop_start_value = now;
        } else if(count[now] == 2) {
            // cout << "end" << i << endl;
            loop_end = i;
            break;
        }
        count[now]++;
    }

    now = X % M;
    sum = X % M;

    if(loop_end == 0) {
        for(ll i = 1; i < N; i++) {
            now = (now*now)%M;
            sum += now;
        }

        cout << sum << endl;
    } else {
        ll res = 1;
        if(loop_start_value == now) {
            res = 0;
            sum = 0;
        } else {
        
            while(true) {
                now = (now*now) % M;
                if(now == loop_start_value) break;
                sum += now;
                res++;
            }
        }

        
        vector<ll> vec(loop_end - loop_start + 1, 0);
        ll loop_sum = 0;
        for(ll i = 1; i < vec.size(); i++) {
            loop_sum += now;
            vec[i] = loop_sum;
            now = (now* now) %M ;
        }
        
        // cout << res << "," <<loop_start << "," << loop_end << "," << loop_start_value<< "," << loop_sum << endl;
        // if((N-res)%(loop_end - loop_start) == 0) cout << sum + ((N-res)/(loop_end-loop_start))*loop_sum << endl;
        // else 
        cout << sum + ((N-res)/(loop_end-loop_start))*loop_sum + vec[(N-res) % (loop_end-loop_start)] << endl;

    }

}
