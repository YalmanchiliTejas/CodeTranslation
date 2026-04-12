#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

template<const long long mod = 1000000007>
struct mint{ //modint
    long long x;
    mint(long long x = 0): x(((x % mod) + mod) % mod) {}
    friend istream& operator >> (istream &s, mint& m){ return s >> m.x; }
    friend ostream& operator << (ostream &s, mint m){ return s << m.x; }
    inline mint& operator += (mint a){ if((x += a.x) >= mod)x -= mod; return *this; }
    inline mint& operator -= (mint a){ if((x += mod - a.x) >= mod)x -= mod; return *this; }
    inline mint& operator *= (mint a){ (x *= a.x) %= mod; return *this; }
    inline mint& operator /= (mint a){ return (*this) *= a.inv(); }
    inline mint operator + (mint a){ mint res(*this); return res += a; }
    inline mint operator - (mint a){ mint res(*this); return res -= a; }
    inline mint operator * (mint a){ mint res(*this); return res *= a; }
    inline mint operator / (mint a){ mint res(*this); return res /= a; }
    inline void takemod(){ x = ((x % mod) + mod) % mod; }
    mint inv(){ return pow(mod - 2); }
    mint pow(long long p){
        mint res(1), tmp(x);
        for(; p; p >>= 1){ if(p & 1)res *= tmp; tmp *= tmp; }
        return res;
    }
};

string K;
int sz, D;
mint<> dp[2][10005][105];

int main(){
    
    cin >> K >> D;
    sz = (int)K.size();
    rep(i, sz)K[i] = K[i] - '0';

    dp[0][0][0] = 1;
    rep(i, sz)rep(j, D){
        rep(k, 10)dp[1][i + 1][(j + k) % D] += dp[1][i][j];
        rep(k, K[i])dp[1][i + 1][(j + k) % D] += dp[0][i][j];
        dp[0][i + 1][(j + K[i]) % D] += dp[0][i][j];
    }

    cout << dp[0][sz][0] + dp[1][sz][0] - mint<>(1) << endl;
    return 0;

}