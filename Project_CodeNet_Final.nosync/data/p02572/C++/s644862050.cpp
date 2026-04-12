#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

struct ModInt
{
    static int _BM;
    long long int m_value;

    int getint() const { return (int) m_value; }
    void _mod() 
    {
        if( m_value < 0 ) m_value += ((-m_value) / _BM + 1) * _BM;
        m_value %= _BM;
    }
    ModInt() { m_value = 0; }
    ModInt(int v) { m_value = (_LL) v; _mod(); }
    ModInt(_LL v) { m_value = (_LL) v; _mod(); }    
    ModInt(const ModInt &t) { m_value = t.getint(); }
    ModInt& operator += ( int v ) { m_value += v; _mod(); return *this; }
    ModInt& operator -= ( int v ) { m_value -= v; _mod(); return *this; }
    ModInt& operator *= ( int v ) { m_value *= v; _mod(); return *this; }
    ModInt& operator += ( _LL v ) { return (*this) += (int)(v % _BM); }
    ModInt& operator -= ( _LL v ) { return (*this) -= (int)(v % _BM); }
    ModInt& operator *= ( _LL v ) { return (*this) *= (int)(v % _BM); }
    ModInt& operator += ( const ModInt &t ) { (*this) += t.getint(); return (*this); }
    ModInt& operator *= ( const ModInt &t ) { (*this) *= t.getint(); return (*this); }
    ModInt& operator -= ( const ModInt &t ) { (*this) -= t.getint(); return (*this); }
    static int reciprocal(_LL a)
    {
        _LL b = _BM, u = 1, v = 0;
        while (b) {
            _LL t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= _BM; 
        if (u < 0) u += _BM;
        return (int)u;
    }
    static int reciprocal(int a) { return reciprocal((_LL) a); }

    ModInt& operator /= ( const ModInt &t ) { (*this) /= t.getint(); return (*this); }
    ModInt& operator /= ( int v ) { (*this) *= reciprocal(v); return *this; }    
    ModInt& operator /= ( _LL v ) { (*this) *= reciprocal(v); return *this; }    
    const ModInt operator + (const ModInt &t) const { ModInt ans(*this); return ans += t; }
    const ModInt operator + (int t)  const { ModInt ans(*this); return ans += t; }
    const ModInt operator + (_LL t)  const { ModInt ans(*this); return ans += t; }        
    const ModInt operator - (const ModInt &t) const { ModInt ans(*this); return ans -= t; }
    const ModInt operator - (int t)  const { ModInt ans(*this); return ans -= t; }
    const ModInt operator - (_LL t)  const { ModInt ans(*this); return ans -= t; }        
    const ModInt operator * (const ModInt &t) const { ModInt ans(*this); return ans *= t; }
    const ModInt operator * (int t)  const { ModInt ans(*this); return ans *= t; }
    const ModInt operator * (_LL t)  const { ModInt ans(*this); return ans *= t; }
    const ModInt operator / (const ModInt &t) const { ModInt ans(*this); return ans /= t; }
    const ModInt operator / (int t)  const { ModInt ans(*this); return ans /= t; }
    const ModInt operator / (_LL t)  const { ModInt ans(*this); return ans /= t; }

    bool operator == (int t) { return getint() == t; }

    static int modadd( int a, int b ) { ModInt t(a); t += b; return t.getint(); }
    static int modminus( int a, int b ) { ModInt t(a); t -= b; return t.getint(); }
    static int modmul( int a, int b ) { ModInt t(a); t *= b; return t.getint(); }
    static int modadd( _LL a, _LL b ) { ModInt t(a); t += b; return t.getint(); }
    static int modminus( _LL a, _LL b ) { ModInt t(a); t -= b; return t.getint(); }    
    static int modmul( _LL a, _LL b ) { ModInt t(a); t *= b; return t.getint(); } 
    static int modpow(int a, int b) { return modpow((_LL) a, (_LL)b); }
    static int modpow(_LL a, _LL b)
    {
        ModInt ans(1);
        int heap[64];
        heap[0] = (a % _BM);
        for( int bit = 0; b >= (((_LL)1) << bit); bit++ )
        {
            if( bit > 0 ) heap[bit] = modmul( heap[bit - 1], heap[bit - 1] );
            if( b & (((_LL)1) << bit) )
            {
                ans *= heap[bit];
            }
        }
        return ans.getint();
    }

    static int getCombination(_LL n, _LL r)
    {
        _LL ans;
        ans = 1;
        for(_LL i = 0; i < r; i++) ans = modmul(ans, n - i);
        _LL inv = 1;
        for(_LL i = 0; i < r; i++) inv = modmul(inv, i + 1);
        return modmul(ans, (_LL) reciprocal(inv));
    }

    static int combination(int n, int r)
    {
        int *fac = (int *)malloc(sizeof(int) * (n + 1));
        int *facinv = (int *)malloc(sizeof(int) * (n + 1));
        fac[0] = 1;
        for( int k = 1; k <= n; k++) fac[k] = modmul(k, fac[k - 1]);
        facinv[n] = reciprocal( fac[n] );
        for( int k = n ; k > 0; k--) facinv[k - 1] = modmul(k, facinv[k]);

        ModInt ans(fac[n]);
        ans *= facinv[r];
        ans *= facinv[n - r];

        free(fac);
        free(facinv);
        return ans.getint();
    }
};

int ModInt::_BM = 1000000007;

int main()
{
    int n; cin >> n;
    vector<_LL> a(n);
    rep(i, n) cin >> a[i];
    ModInt asum = 0;
    rep(i, n) asum += a[i];
    ModInt asum2 = asum * asum;
    rep(i, n) 
    {
        ModInt at = a[i];
        at *= a[i];
        asum2 -= at;
    }

    asum2 /= 2;
    cout << asum2.getint() << endl;

    return 0;    
}