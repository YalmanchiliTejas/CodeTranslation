#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i,n) for(ll (i)=0; (i)<(ll)(n); (i)++)
#define frep(i,m,n) for(ll (i)=(m); (i)<=(ll)(n); (i)++)
#define rrep(i,n) for(ll (i)=(n)-1; (i)>-1; (i)--)
#define frrep(i,m,n) for(ll (i)=(n); (i)>(ll)(m); (i)--)
#define ALL(x) (x).begin(), (x).end()
#define SQR(x) (x)*(x)
#define CEIL(a,b) ((a)+(b)-1) /(b)

const int INF = 1001001001;
const ll MOD = 1000000007;
const int MAX_N = 101010;

// A:array of pair, N:size of array
void sort_second(vector<pair<ll, ll>> &A, int N);
// a^n
ll a_n(ll a, ll n);
// make vector of (n!)%MOD, (n!)^(-1)%MOD to calculate nCk
void factorial_map(vector<ll> &n, vector<ll> &ninv);
// a^(-1) % MOD 
ll inv(ll a);
// map of prime factorization
void prime_map(map<ll, ll> &a, ll n);
//list of prime (is_prime.size() = n + 1, primes.size() = 0)
void prime_list(ll n, vector<ll> &primes, vector<bool> &is_prime);
// get gcd from prime map
ll gcd_map(map<ll, ll> a, map<ll, ll> b);
// get lcm from prime map
ll lcm_map(map<ll, ll> a, map<ll, ll> b);
// get gcd
ll my_gcd(ll a, ll b);
// calculate nCk
ll nCk(ll n, ll k);
// get abs
ll my_abs(ll a);
// z-algorithm (s.size() == a.size())
void z_algorithm(string s, vector<int> &a);

class Unionfind {
    public:
        vector<ll> par, siz, rank;
        Unionfind();
        ll root(ll x);
        void merge(ll x, ll y);
        bool issame(ll x, ll y);
        ll size(ll x);
};

ll mod_time(ll a, ll b, ll c) {
    return (((a*b)%MOD)*c)%MOD;
}

int main() {
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<ll> nfac(202020), ninv(202020);
    factorial_map(nfac, ninv);
    
    frep(i, 0, n-1) {
        frep(j, 0, m-1) {
            if(i != 0 && j != 0) {
                ans += 2*(n-i)*(m-j)*(i+j);
                ans %= MOD;
            }
            else {
                ans += (n-i)*(m-j)*(i+j);
                ans %= MOD;
            }
        }
    }

    ans *= mod_time(nfac[n*m-2], ninv[k-2], ninv[n*m-k]);
    ans %= MOD;

    cout << ans << endl;
    return 0;
}

void sort_second(vector<pair<ll, ll>> &A, int N) {
    rep(i, N) swap(A.at(i).first, A.at(i).second);
    sort(ALL(A));
    rep(i, N) swap(A.at(i).first, A.at(i).second);
}
ll a_n(ll a, ll n) { 
    if(n == 0) return 1;
    
    ll ret = a, count = 1;
    while(count * 2 < n) {
        ret *= ret;
        ret %= MOD;
        count *= 2;
    }
    if(count == n) return ret;
    else return (ret * a_n(a, n-count))%MOD ;
}

/* calculate a^n with no recursive process (%MOD)
ll a_n(ll a, ll n) { 
    ll ret = a, count = 1;
    int num = 1;
    vector<ll> memory(100);
    memory.at(0) = a;

    while(count * 2 < n) {
        ret *= ret;
        ret %= MOD;
        count *= 2;
        memory.at(num) = ret;
        num++;
    }
    if(count == n) return ret;
    else {
        bitset<100> bit = bitset<100>(n-count);
        rep(i, 100) {
            if(bit.test(i)) ret = (ret * memory.at(i)) % MOD;
        }
        return ret;
    }    
}
*/

void factorial_map(vector<ll> &n, vector<ll> &ninv) {
    n[0] = 1;
    ninv[0] = 1;
    for(ll i = 1; i < n.size(); i++) n[i] = (n[i-1] * i) % MOD;
    ninv[n.size()-1] = inv(n[n.size()-1]);
    for(ll i = n.size() - 2; i > 0; i--) ninv[i] = (ninv[i+1] * (i+1)) % MOD;
}

ll inv(ll a) {
    return a_n(a, MOD-2);
}

void prime_map(map<ll, ll> &a, ll n) {
    while((n%2) == 0) {
        n /= 2;
        if(a.count(2)) a.at(2)++;
        else a[2] = 1;
    }
    for(ll i = 3; i*i <= n; i+=2) {
        while((n%i) == 0) {
            n /= i;
            if(a.count(i)) a.at(i)++;
            else a[i] = 1;
        }
    }
    if(n != 1) a[n] = 1;
}

ll gcd_map(map<ll, ll> a, map<ll, ll> b) {
    ll ret = 1;
    for(auto p : a) {
        auto key = p.first;
        auto value = p.second;
        if(b.count(key)) {
            if(value > b.at(key)) ret *= a_n(key, b.at(key));
            else ret *= a_n(key, value);
        }
    }
    return ret;
}

ll lcm_map(map<ll, ll> a, map<ll, ll> b) {
    ll ret = 1;
    for(auto p: a) {
        auto key = p.first;
        auto value = p.second;
        if(b.count(key)) {
            if(value > b.at(key)) ret *= a_n(key, value);
            else ret *= a_n(key, b.at(key));
        }
        else {
            ret *= a_n(key, value);
        }
    }
    for(auto p: b) {
        auto key = p.first;
        auto value = p.second;
        if(a.count(key)) {
            continue;
        }
        else {
            ret *= a_n(key, value);
        }
    }
    return ret;
}

ll my_gcd(ll a, ll b) {
    if(b == 0) return a;
    return my_gcd(b, a%b);
}

ll nCk(ll n, ll k) {
    ll kfac = 1, ret = 1;
    for(ll i = 1; i <= k; i++) {
        kfac = (kfac * i) % MOD;
    }
    for(ll i = n; i >= n-k+1; i--) {
        ret = (ret * i) % MOD;
    }
    ret = (ret * inv(kfac)) % MOD;
    return ret;
}

void prime_list(ll n, vector<ll> &primes, vector<bool> &is_prime) {
    ll p = 0;
    rep(i, n + 1) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(ll j = 2*i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

ll my_abs(ll a) {
    if(a >= 0) return a;
    else return -1 *a;
}

Unionfind::Unionfind() {
    par.resize(MAX_N);
    siz.resize(MAX_N);
    rank.resize(MAX_N);
    rep(i, MAX_N) {
        par[i] = i;
        siz[i] = 1;
        rank[i] = 0;
    }
}
ll Unionfind::root(ll x) {
    if(par[x] == x) return x;
    else {
        return par[x] = root(par[x]);
    }
}
void Unionfind::merge(ll x, ll y) {
    x = root(x);
    y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
        par[x] = y;
        siz[y] += siz[x];
    }
    else {
        par[y] = x;
        siz[x] += siz[y];
        if(rank[x] == rank[y]) rank[x]++;
    }
}
bool Unionfind::issame(ll x, ll y) {
    return root(x) == root(y);
}
ll Unionfind::size(ll x) {
    return siz[root(x)];
}

void z_algorithm(string s, vector<int> &a) {
    a.at(0) = s.size();
    int i = 1, j = 0;
    while(i < s.size()) {
        while((i+j < s.size()) && (s.at(j) == s.at(i+j))) j++;
        a.at(i) = j;
        if(j == 0) {
            i++;
            continue;
        }
        int k = 1;
        while ((i+k < s.size()) && (k+a.at(k) < j)) {
            a.at(i+k) = a.at(k);
            k++;
        }
        i += k;
        j -= k;
    }
}