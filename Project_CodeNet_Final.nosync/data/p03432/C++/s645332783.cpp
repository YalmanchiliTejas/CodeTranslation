#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
#else
#endif


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define vi vector<int>
#define vll vector<ll>

const int g = 3, mod =  998244353, p =  998244353;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
    int x = 1 % mod;
    while(b){
        if(b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int MX = 21;
int W[1 << MX], invW[1 << MX]; // max polynomial input/output -> (1 << MX)
int maxn;

void precompute_powers(){
    int p2 = p - 1, MAXN = 0;
    while(p2 % 2 == 0){
        p2 >>= 1;
        MAXN ++;
    }
    MAXN = min(MAXN, MX);
    int g1 = powr(g, (p - 1) >> MAXN);
    maxn = 1 << MAXN;
    int st = 1;
    for(int i = 0; i < maxn; i++){
        W[i] = st;
        st = mul(st, g1);
    }
    for(int i = 0; i < maxn; i++){
        invW[i] = (i == 0) ? 1 : W[maxn - i];
    }
}

void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        for (int i=0; i<n; i+=len) {
            int ind = 0,ADD = maxn/len;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = mul(a[i+j+len/2], (invert?invW[ind]:W[ind]));
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                ind += ADD;
            }
        }
    }
    if (invert){
        int invn = inv(n);
        for (int i=0; i<n; ++i) a[i] = mul(a[i], invn);
    }
}

vi add(vi a, vi b){
    vi ret(max(a.size(), b.size()));
    for(int i = 0; i < ret.size(); i++){
        ret[i] = add(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
    }
    return ret;
}

vi sub(vi a, vi b){ 
    vi ret(max(a.size(), b.size()));
    for(int i = 0; i < ret.size(); i++){
        ret[i] = sub(i < a.size() ? a[i] : 0, i < b.size() ? b[i] : 0);
    }
    return ret;
}

vi mul(vi a, vi b, int upper_limit = 1e9){
    int sz = a.size() + b.size() - 1;
    int k = 0;
    while((1 << k) < sz) k++;
    a.resize(1 << k); b.resize(1 << k);
    fft(a, 0); fft(b, 0);
    for(int i = 0; i < (1 << k); i++)
        a[i] = mul(a[i], b[i]);
    fft(a, 1);
    a.resize(min(upper_limit, sz));
    return a;
}

vi vmul(vector<vi> & v){
    if(v.size() == 1) return v[0];
    int mid = v.size() >> 1;
    vector<vi> lft(v.begin(), v.begin()+mid);
    vector<vi> rgt(v.begin() + mid, v.end());
    return mul(vmul(lft), vmul(rgt));
}

vi mul_scalar(vi v, int k){
    for(auto & it : v) it = mul(k, it);
    return v;   
}

vi get_first(vi v, int k){
    v.resize(min((int)v.size(), k));
    return v;
}

vi inverse(vi a, int sz){
    assert(a[0] != 0);
    vi x = {inv(a[0])};
    while(x.size() < sz){
        vi temp(a.begin(), a.begin() + min(a.size(), 2 * x.size()));
        vi nx = mul(mul(x, x), temp);
        x.resize(2 * x.size());
        for(int i = 0; i < x.size(); i++)
            x[i] = sub(add(x[i], x[i]), nx[i]);
    }
    x.resize(sz);
    return x;
}

vi truncate_end(vi v){
    while(!v.empty() && v.back() == 0) v.pop_back();
    if(v.empty()) v = {0};
    return v;
}

// maybe print inverted values for a better form?
void print(vi v, bool invert = 0){
    cerr << "["; 
    for(int i = 0; i < v.size(); i++){
        if(invert) v[i] = inv(v[i]);
        cerr << v[i];
        if(i + 1 != v.size()) cerr <<" ";
        else cerr << "]";
    }
    cerr << endl;
}

vi _inv;
// _inv = inverse(reverse(g))
// useful to store when g is fixed across queries

pair<vi, vi> divmod(vi f, vi g){
    if(f.size() < g.size()) return {{0}, f};
    int sz = f.size() - g.size() + 1;
    reverse(f.begin(), f.end()); reverse(g.begin(), g.end());
    vi inv2 = _inv; 
    inv2.resize(sz);
    vi _p = f; _p.resize(sz);
    vi q = mul(inv2, _p);
    q.resize(sz);
    reverse(q.begin(), q.end()); reverse(f.begin(), f.end()); reverse(g.begin(), g.end());
    return {q, truncate_end(sub(f, mul(g, q)))};
}

vi differentiate(vi f){
    for(int i = 0; i + 1 < f.size(); i++) f[i] = mul(i + 1, f[i + 1]);
    if(!f.empty()) f.resize(f.size() - 1);
    if(f.empty()) f = {0};
    return f;
}

vi integrate(vi f, int c = 0){
    f.resize(f.size() + 1);
    for(int i = f.size() - 1; i >= 1; i--) f[i] = mul(f[i - 1], inv(i));
    f[0] = c;
    return f;
}

// make leading coeff of x^0 to be 1 first.
// first k coefficients
vi Log(vi f, int k){
    if((int)f.size() > k + 1) f.resize(k + 1);
    assert(f[0] == 1);
    return integrate(mul(differentiate(f), inverse(f, k), k))   ;
}

vi Exp(vi f, int k){
    if((int)f.size() > k + 1) f.resize(k + 1);
    assert(f[0] == 0);
    vi g = {1};
    while(g.size() < k){
        int curr_sz = g.size();
        g = mul(g, get_first(add(f, sub({1}, Log(g, 2 * curr_sz))), 2 * curr_sz), 2 * curr_sz);
    }

    g.resize(k);
    return g;
}

vi powr(vi X, long long n, int k){
    // Exp(Y * log(X))
    int common = X[0];
    int inv_com = inv(common);
    X = mul_scalar(X, inv_com);
    n %= mod;
    vi ret = Exp(mul_scalar(Log(X, k + 1), n), k);
    ret.resize(k);
    ret = mul_scalar(ret, powr(common, n));
    return ret;
}

int compute(vi & f, int x){
    int ret = 0;
    if(f.empty()) return 0;
    for(int i = f.size() - 1; i >= 0; i--){
        ret = add(mul(ret, x), f[i]);
    }
    return ret;
}

vi compute(vi & f, vi & x){
    vector<vi> tree(4 * x.size());
    function<vi(int, int, int)> make = [&](int l, int r, int ind){
        if(l==r){
            vi ret = {sub(0, x[l]), 1};
            return tree[ind] = ret;
        }
        int mid = (l + r) >> 1;
        return tree[ind] = mul(make(l, mid, ind << 1), make(mid + 1, r, ind << 1 | 1) );
    }; make(0, x.size() - 1, 1);

    function<vi(int,int,int, vi)> eval = [&](int l, int r, int ind, vi p){
        if(r - l < 16){
            vi ret;
            for(int i = l; i <= r; i++) ret.push_back(compute(p, x[i]));
            return ret;
        }
        int mid = (l + r) >> 1;
        vi Y = eval(mid + 1, r, ind << 1 | 1, divmod(p, tree[ind << 1 | 1]).second);
        vi X = eval(l, mid, ind << 1, divmod(p, tree[ind << 1]).second);
        for(auto it : Y) X.push_back(it);
        return X;
    };
    return eval(0, x.size() - 1, 1, f);
}

const int N = 1e4 + 10;
int fact[N], invfact[N];
void pre(){
	fact[0] = invfact[0] = 1;
	for(int i = 1;i < N; i++) fact[i] = mul(i, fact[i - 1]);
	invfact[N - 1] = inv(fact[N - 1]);
	for(int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
	assert(invfact[1] == 1);
}

inline int C(int n, int k){
	if(n < k || k < 0) return 0;
	return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

vector<int> dp, oldDp, u;

int main(){
    precompute_powers();
	pre();
    int n, m;
	cin >> n >> m;
	vi v(n + 1);
	for(int i = 1; i <= n; i++) v[i] = invfact[i + 2];
	dp.resize(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= m; i++){
		oldDp = dp;
		u.resize(dp.size());
		for(int i = 0; i < dp.size(); i++) u[i] = mul(dp[i], invfact[i]);
		dp = mul(u, v, n + 1);
		// print(dp);
		// print(v);
		for(int i = 0; i <= n; i++) dp[i] = mul(dp[i], fact[i + 2]);
		// print(dp);
		for(int i = 0; i <= n; i++) dp[i] = add(dp[i], mul(add(1, C(i + 1, 2)), oldDp[i]));
		// print(dp);
	}

	int ans = 0;
	for(int i = 0; i <= n; i++)
		ans = add(ans, mul(C(n, i), dp[i]));
	printf("%d\n", ans);
}   