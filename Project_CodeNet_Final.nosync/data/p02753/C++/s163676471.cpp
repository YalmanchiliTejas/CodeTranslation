#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
//#define int ll
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(),(a).end()
#define ln(a) cout << (a) << endl
#define debug(a, n) rep(hoge, (n)) printf("%d%c", a[hoge], hoge == (n) - 1? '\n' : ' ');
#define pb push_back
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define EPS 0.000000001

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<double, pair<double, double> > DDPP;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int ddx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int extgcd(int a, int b, int& x, int&y) {
    int d = a;
    if(b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else {
        x = 1;
        y = 0;
    }
    return d;
}

int inv(int a, int mod) {
    int x, y;
    extgcd(a, mod, x, y);
    return (x + mod) % mod;
}

int pow(int x, int n) {
    int res = 1;
    while(n > 0) {
        if(n & 1) res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

template<int mod> struct modint {
    int val;

    modint() {
        val = 0;
    }
    modint(int _val) {
        if(_val < 0) _val += mod * (-_val / mod + 1);
        val = _val % mod;
    }

    modint &operator=(const modint &x) {
        val = x.val;
        return *this;
    }
    bool operator==(const modint &rhs) const {return val == rhs.val;}
    bool operator<(const modint &rhs) const {return val < rhs.val;}
    bool operator>(const modint &rhs) const {return val > rhs.val;}
    bool operator<=(const modint &rhs) const {return val <= rhs.val;}
    bool operator>=(const modint &rhs) const {return val >= rhs.val;}
    bool operator!=(const modint &rhs) const {return val != rhs.val;}
    modint operator+(const modint &rhs) const {return modint<mod>(val + rhs.val);}
    modint operator-(const modint &rhs) const {return modint<mod>(val - rhs.val);}
    modint operator*(const modint &rhs) const {return modint<mod>((int)((ll)val * rhs.val % mod));}
    modint operator/(const modint &rhs) const {return modint<mod>((int)((ll)val * inv(rhs.val, mod) % mod));}
    modint &operator+=(const modint &rhs) {
        val = modint<mod>(val + rhs.val).val;
        return *this;
    }
    modint &operator-=(const modint &rhs) {
        val = modint<mod>(val - rhs.val).val;
        return *this;
    }
    modint &operator*=(const modint &rhs) {
        val = (int)((ll)val * rhs.val % mod);
        return *this;
    }
    modint &operator/=(const modint &rhs) {
        val = (int)((ll)val * inv(rhs.val, mod) % mod);
        return *this;
    }
    modint& operator++() {
        val = (val + 1) % mod;
        return *this;
    }
    modint operator++(signed) {
        modint<mod> m = *this;
        val = (val + 1) % mod;
        return m;
    }
    modint& operator--() {
        val = (val + mod - 1) % mod;
        return *this;
    }
    modint operator--(signed) {
        modint<mod> m = *this;
        val = (val + mod - 1) % mod;
        return m;
    }
};

struct unitree {
    int *par, *rank, *sz;

    unitree(int n) {
        par = new int[n];
        rank = new int[n];
        sz = new int[n];
        for(int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
            sz[i] = 1;
        }
    }

    int root(int x) {
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(rank[x] < rank[y]) {
            par[x] = y;
            sz[y] += sz[x];
        }else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
            sz[x] += sz[y];
        }
    }
    
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int siz(int x) {
        return sz[root(x)];
    }
};

struct vect {
    ll x, y;
    vect() {
        x = 0;
        y = 0;
    }
    vect(ll x, ll y) {
        this->x = x;
        this->y = y;
    }

    int posi() const {
        if(x == 0 && y == 0) exit(1);
        if(x > 0 && y == 0) return 0;
        if(x > 0 && y > 0) return 1;
        if(x == 0 && y > 0) return 2;
        if(x < 0 && y > 0) return 3;
        if(x < 0 && y == 0) return 4;
        if(x < 0 && y < 0) return 5;
        if(x == 0 && y < 0) return 6;
        if(x > 0 && y < 0) return 7;
    }

    int posi(const vect& v) const {
        ll s = x * v.y - y * v.x;
        ll c = x * v.x + y * v.y;
        if(s == 0 && c == 0) exit(1);
        if(s == 0 && c > 0) return 0;
        if(s > 0 && c > 0) return 1;
        if(s > 0 && c == 0) return 2;
        if(s > 0 && c < 0) return 3;
        if(s == 0 && c < 0) return 4;
        if(s < 0 && c < 0) return 5;
        if(s < 0 && c == 0) return 6;
        if(s < 0 && c > 0) return 7;
    }

    bool operator<(const vect& rhs) {
        int p1 = posi();
        int p2 = rhs.posi();
        if(p1 != p2) return p1 < p2;
        return rhs.x * y < x * rhs.y;
    }
};

struct segtree {
    int n, *dat;

    segtree(int _n, string str) {
        n = 1;
        while(n < _n) n *= 2;
        dat = new int[n * 2 + 1];
        rep(i, _n) dat[n - 1 + i] = 1 << (str[i] - 'a');
        fill(dat + n - 1 + _n, dat + n * 2 - 1, 0);
        for(int i = n - 2; i >= 0; i--) {
            dat[i] = dat[i * 2 + 1] | dat[i * 2 + 2];
        }
    }

    void update(int k, char c) {
        k += n - 1;
        dat[k] = 1 << (c - 'a');
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = dat[k * 2 + 1] | dat[k * 2 + 2];
        }
    }

    int _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return dat[k];
        int vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
        return vl | vr;
    }

    int query(int a, int b) {
        int res = _query(a, b, 0, 0, n);
        int ans = 0;
        while(res) {
            if(res & 1) ans++;
            res >>= 1;
        }
        return ans;
    }
};

signed main() {
    string s;
    cin >> s;
    char c = s[0];
    for(int i = 1; i < 3; i++) {
        if(s[i] != c) {
            ln("Yes");
            return 0;
        }
    }
    ln("No");
}