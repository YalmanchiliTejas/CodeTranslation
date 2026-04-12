#pragma GCC optimize("O2")

#include <bits/stdc++.h>
#ifdef DEBUG
    #include "debug.hpp"
#endif

using namespace std;

#define all(c) (c).begin(), (c).end()
#define traverse(c, it) for(auto it = (c).begin(); it != (c).end(); it++)
#define rep(i, N) for(int i = 0; i < (N); i++)
#define rep1(i, N) for(int i = 1; i <= (N); i++)
#define rep2(i, s, e) for(int i = (s); i <= (e); i++)
#define rep3(i, s, e, d) for(int i = (s); (d) >= 0 ? i <= (e) : i >= (e); i += (d))
#define pb push_back


#ifdef DEBUG
    #define debug(x...) {dbg::depth++; string dbg_vals = dbg::to_string(x); dbg::depth--; dbg::fprint(__func__, __LINE__, #x, dbg_vals);}
    #define light_debug(x) {dbg::light = 1; dbg::dout << __func__ << ":" << __LINE__ << "  " << #x << " = " << x << endl; dbg::light = 0;}
#else
    #define debug(x...)
    #define light_debug(x) 
#endif

template<typename T>
T& ckmin(T& a, T b){ return a = a > b ? b : a; }

template<typename T>
T& ckmax(T& a, T b){ return a = a < b ? b : a; }

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<int mod>
class Modular{
    int value;
    
public:
    Modular(long long x = 0){ value = (int)((x % mod + mod) % mod); }

    inline Modular& operator +=(Modular x){ value += x.value; if(value >= mod) value -= mod; return *this; }

    inline Modular& operator -=(Modular x){ value -= x.value; if(value < 0) value += mod; return *this; }

    inline Modular& operator *=(Modular x){ value = (int)((long long)x.value * value % mod); return *this; }

    inline Modular operator -(){ return Modular(-value); }

    inline Modular& operator ++(){ return *this += 1; }

    inline Modular& operator --(){ return *this -= 1; }

    inline Modular operator ++(int){ Modular t = *this; *this += 1; return t; }

    inline Modular operator --(int){ Modular t = *this; *this -= 1; return t; }

    Modular pow(int n){ 
        while(n < 0) n += mod - 1;
        Modular v(1), a(value);
        for(; n; a *= a, n >>= 1)
            if(n & 1) v *= a;
        return v;
    }

    inline Modular& operator /=(Modular x){ *this *= x.pow(-1); } //TODO : Make this Extended Euclid to handle composite moduli.

    inline Modular operator +(Modular x){ return x += *this; }

    inline Modular operator -(Modular x){ return *this + (-x); }

    inline Modular operator *(Modular x){ return x *= *this; }

    inline Modular operator /(Modular x){ return (*this) * x.pow(-1); } 

    inline bool operator ==(Modular x){ return value == x.value; }

    inline bool operator !=(Modular x){ return value != x.value; }

    inline operator int(){ return value; }

    Modular fact(){ 
        Modular x(1);
        for(int i = 1; i <= value; ++i) x *= i;
        return x;
    }

    friend ostream& operator <<(ostream& os, Modular x){ return os << x.value; }

    friend istream& operator >>(istream& is, Modular& x){ is >> x.value; x.value %= mod; return is; }
};

const int MOD = 1e9 + 7;

string K;
int D;
Modular<MOD> dp[10005][100][2];
bool ch[10005][100][2];

Modular<MOD> rec(int i, int r, bool b){
	if(i == (int)K.size()) 
		return Modular<MOD>(r == 0);
	if(ch[i][r][b]) 
		return dp[i][r][b];
	
	ch[i][r][b] = 1;
	Modular<MOD> ans = 0;
	rep(d, b ? K[i] - '0' + 1 : 10) 
		ans += rec(i + 1, ((r - d) % D + D) % D, b && d == K[i] - '0');
	return dp[i][r][b] = ans;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    #ifdef DEBUG
        freopen("debug", "w", stderr);
    #endif

    cin >> K >> D;
    cout << rec(0, 0, 1) - Modular<MOD>(1) << '\n';
   

    #ifdef DEBUG
        dbg::dout << "\nExecution time: " << clock() << "ms\n";
    #endif

    return 0;
}
