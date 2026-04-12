#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}


template <unsigned int mod>
class ModInt {
private:
    unsigned int v;
    static unsigned int norm(const unsigned int& x){ return x < mod ? x : x - mod; }
    static ModInt make(const unsigned int& x){ ModInt m; return m.v = x, m; }
    static ModInt inv(const ModInt& x){ return make(inverse(x.v, mod)); }
    static unsigned int inverse(int a, int m){
        int u[] = {a, 1, 0}, v[] = {m, 0, 1}, t;
        while(*v){
            t = *u / *v;
            swap(u[0] -= t * v[0], v[0]), swap(u[1] -= t * v[1], v[1]), swap(u[2] -= t * v[2], v[2]);
        }
        return (u[1] % m + m) % m;
    }

public:
    ModInt() : v{0}{}
    ModInt(const long long val) : v{norm(val % mod + mod)} {}
    ModInt(const ModInt<mod>& n) : v{n()} {}
    explicit operator bool() const noexcept { return v != 0; }
    bool operator!() const noexcept { return !static_cast<bool>(*this); }
    ModInt& operator=(const ModInt& n){ return v = n(), (*this); }
    ModInt& operator=(const long long val){ return v = norm(val % mod + mod), (*this); }
    ModInt operator+() const { return *this; }
    ModInt operator-() const { return v == 0 ? make(0) : make(mod - v); }
    ModInt operator+(const ModInt& val) const { return make(norm(v + val())); }
    ModInt operator-(const ModInt& val) const { return make(norm(v + mod - val())); }
    ModInt operator*(const ModInt& val) const { return make((long long)v * val() % mod); }
    ModInt operator/(const ModInt& val) const { return *this * inv(val); }
    ModInt& operator+=(const ModInt& val){ return *this = *this + val; }
    ModInt& operator-=(const ModInt& val){ return *this = *this - val; }
    ModInt& operator*=(const ModInt& val){ return *this = *this * val; }
    ModInt& operator/=(const ModInt& val){ return *this = *this / val; }
    ModInt operator+(const long long val) const { return ModInt{v + val}; }
    ModInt operator-(const long long val) const { return ModInt{v - val}; }
    ModInt operator*(const long long val) const { return ModInt{(long long)v * (val % mod)}; }
    ModInt operator/(const long long val) const { return ModInt{(long long)v * inv(val)}; }
    ModInt& operator+=(const long long val){ return *this = *this + val; }
    ModInt& operator-=(const long long val){ return *this = *this - val; }
    ModInt& operator*=(const long long val){ return *this = *this * val; }
    ModInt& operator/=(const long long val){ return *this = *this / val; }
    bool operator==(const ModInt& val) const { return v == val.v; }
    bool operator!=(const ModInt& val) const { return !(*this == val); }
    bool operator==(const long long val) const { return v == norm(val % mod + mod); }
    bool operator!=(const long long val) const { return !(*this == val); }
    unsigned int operator()() const { return v; }
    friend ModInt operator+(const long long val, const ModInt& n) { return n + val; }
    friend ModInt operator-(const long long val, const ModInt& n) { return ModInt{val - n()}; }
    friend ModInt operator*(const long long val, const ModInt& n) { return n * val; }
    friend ModInt operator/(const long long val, const ModInt& n) { return ModInt{val} / n; }
    friend bool operator==(const long long val, const ModInt& n) { return n == val; }
    friend bool operator!=(const long long val, const ModInt& n) { return !(val == n); }
    friend istream& operator>>(istream& is, ModInt& n){
        unsigned int v;
        return is >> v, n = v, is;
    }
    friend ostream& operator<<(ostream& os, const ModInt& n){ return (os << n()); }
    friend ModInt mod_pow(ModInt x, long long n){
        ModInt ans = 1;
        while(n){
            if(n & 1) ans *= x;
            x *= x, n >>= 1;
        }
        return ans;
    }
};

#define MOD 1000000007
using mod = ModInt<MOD>;

unsigned int mod_pow(unsigned int a, unsigned int n, unsigned int _mod){
    unsigned int ret = 1;
	while(n){
		if(n & 1) ret = (unsigned long long)ret * a % _mod;
		a = (unsigned long long)a * a % _mod;
		n >>= 1;
	}
	return ret;
}

template<unsigned int _mod>
class NTT {
public:
	unsigned int get_mod() const { return _mod; }
    void ntt(vector<int>& a, const bool rev = false){
        unsigned int i, j, k, l, p, q, r, s;
        const unsigned int size = a.size();
    	if(size == 1) return;
    	vector<int> b(size);
    	r = rev ? (_mod - 1 - (_mod - 1) / size) : (_mod - 1) / size;
    	s = mod_pow(3, r, _mod);
    	vector<unsigned int> kp(size / 2 + 1, 1);
    	for(i = 0; i < size / 2; ++i) kp[i + 1] = (unsigned long long)kp[i] * s % _mod;
    	for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
    		for(j = 0, r = 0; j < l; ++j, r += i){
    			for(k = 0, s = kp[i * j]; k < i; ++k){
    				p = a[k + r], q = a[k + r + size / 2];
    				b[k + 2 * r] = ((p + q < _mod) ? (p + q) : (p + q - _mod));
    				b[k + 2 * r + i] = (unsigned long long)((p >= q) ? (p - q) : (_mod - q + p)) * s % _mod;
    			}
    		}
    		swap(a, b);
    	}
        if(rev){
            s = mod_pow(size, _mod - 2, _mod);
            for(i = 0; i < size; ++i){ a[i] = (unsigned long long)a[i] * s % _mod; }
        }
    }
	void convolution(const vector<int>& a, const vector<int>& b, vector<int>& _a, vector<int>& _b,
        unsigned int asize, unsigned int bsize, unsigned int _size){
		unsigned int ntt_size = 1;
		while(ntt_size < asize + bsize) ntt_size *= 2;
        _a.assign(ntt_size, 0), _b.assign(ntt_size, 0);
        for(unsigned int i = 0; i < asize; ++i){ _a[i] = ((a[i] < (int)_mod) ? a[i] : (a[i] % _mod)); }
        for(unsigned int i = 0; i < bsize; ++i){ _b[i] = ((b[i] < (int)_mod) ? b[i] : (b[i] % _mod)); }
		ntt(_a), ntt(_b);
		for(unsigned int i = 0; i < ntt_size; ++i){
			_a[i] = (unsigned long long)_a[i] * _b[i] % _mod;
		}
        ntt(_a, true);
        _a.resize(_size);
	}
};

typedef NTT<167772161> NTT_1;
typedef NTT<469762049> NTT_2;
typedef NTT<1224736769> NTT_3;

vector<int> convolute(const vector<int>& a, const vector<int>& b, int asize, int bsize, int _size){
	NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
    vector<int> x, _x, y, _y, z, _z;
	ntt1.convolution(a, b, x, _x, asize, bsize, _size);
    ntt2.convolution(a, b, y, _y, asize, bsize, _size);
    ntt3.convolution(a, b, z, _z, asize, bsize, _size);
	const unsigned int m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
	const unsigned int m1_inv_m2 = mod_pow(m1, m2-2, m2);
	const unsigned int m12_inv_m3 = mod_pow((unsigned long long)m1 * m2 % m3, m3-2, m3);
	const unsigned int m12_mod = (unsigned long long)m1 * m2 % MOD;
	vector<int> res(_size);
	for(unsigned int i = 0; i < x.size(); ++i){
	    unsigned int v1 = ((unsigned long long )y[i] + m2 - x[i]) *  m1_inv_m2 % m2;
	    unsigned int v2 = ((unsigned long long)z[i] + m3 - (x[i] + (unsigned long long)m1 * v1) % m3) * m12_inv_m3 % m3;
	    res[i] = (x[i] + (unsigned long long)m1 * v1 + (unsigned long long)m12_mod * v2) % MOD;
	}
    return res;
}

unsigned int add(const unsigned int x, const unsigned int y)
{
    return (x + y < MOD) ? x + y : x + y - MOD;
}
 
unsigned int sub(const unsigned int x, const unsigned int y)
{
    return (x >= y) ? (x - y) : (MOD - y + x);
}
 
unsigned int mul(const unsigned int x, const unsigned int y)
{
    return (unsigned long long)x * y % MOD;
}
 
unsigned int mod_pow(unsigned int x, unsigned int n)
{
    unsigned int res = 1;
    while(n > 0){
        if(n & 1){ res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
 
unsigned int inverse(const unsigned int x)
{
    return mod_pow(x, MOD - 2);
}
 
vector<int> polynomial_inverse(const vector<int>& a, int r)
{
    assert(a[0] != 0);
    vector<int> h = {(int)inverse(a[0])};
    int t = 1;
    for(int i = 0; t < r; ++i){
        t <<= 1;
        vector<int> res = convolute(a, convolute(h, h, t / 2, t / 2, t), min((int)a.size(), t), t, t);
        for(int j = 0; j < t; ++j){
            res[j] = sub(0, res[j]);
            if(j < t / 2) res[j] = add(res[j], mul(2, h[j]));
        }
        swap(h, res);
    }
    h.resize(r);
    return h;
}

mod dp[200010][2][2];
int main(){
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    if(s[0]=='R'){
        rep(i,m){
            if(s[i]=='R'){
                s[i] ='B';
            }else{
                s[i] ='R'; 
            }
        }
    }
    int a = inf;
    int c = 0;
    bool flag = 1;
    rep(i,m){
        if(s[i]=='B'){
            c++;
        }else{
            if(flag){
                flag = 0;
                chmin(a,c);
            }else if(c%2==1){
                chmin(a,c); 
            }
            c = 0;   
        }
    }
    if(a==inf){
        dp[0][0][0] = 1;
        dp[0][1][1] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<2;j++){
                if(j==0){
                    dp[i][j][0] += dp[i-1][1][0];
                    dp[i][j][1] += dp[i-1][1][1];
                }else{
                    dp[i][j][0] += dp[i-1][1][0] + dp[i-1][0][0];
                    dp[i][j][1] += dp[i-1][1][1] + dp[i-1][0][1];    
                }
            }
        }
        cout << dp[n-1][1][0] + dp[n-1][1][1] + dp[n-1][0][1] << endl;
    }else{
        int len = (a/2)*2+1;
        vector<int> X(n+1),Y(n+1);
        len++;
        len = min(n,len);
        for(int i=2;i<=len;i+=2){
            X[i] = i;
        }
        Y[0] = 1;
        for(int i=2;i<=len;i+=2){
            Y[i] = MOD-1;
        }
        Y =polynomial_inverse(Y,n+1);
        X = convolute(X,Y,(int)X.size(),(int)Y.size(),n+1);
        cout << X[n] << endl;
    }
    return 0;
}
