#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<long long Mod>
struct mint{
    long long x;
    mint(long long x=0) :x((x% Mod+Mod)%Mod){}

    mint operator-() const { return mint(-x); }

    mint& operator+=(const mint a) {
        if((x += a.x) >= Mod) x -= Mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if((x += Mod-a.x) >= Mod) x -= Mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= Mod;
        return *this;
    }

    mint operator^(long long t) const {
        mint ret(1);
        mint a = *this;
        while(t){
            if(t&1){
                ret *= a;
            }
            a *= a;
            t >>= 1;
        }
        return ret;
    }
    mint inv() const { return *this ^ (Mod-2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }

    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint operator/(const mint a) const { return mint(*this) /= a; }

    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
};

template<typename T>
struct Combination{
private:
    int N;
    vector<T> f, i;
public:
    void init(int n){
        N = n;
        f.resize(N+1); f[0] = T(1);
        for(int j=1; j<=N; j++){
            f[j] = f[j-1] * T(j);
        }
        i.resize(N+1); i[N] = T(1) / f[N];
        for(int j=N-1; j>=0; j--){
            i[j] = i[j+1] * T(j+1);
        }
    }
    T fact(int n){
        return f[n];
    }
    T P(int n, int r){
        return f[n] * i[n-r];
    }
    T C(int n, int r){
        return f[n] * i[r] * i[n-r];
    }
};

int N;
int A, B, C, D;
Combination<mint<MOD>> comb;

bool vis[1001][1001] ={};
mint<MOD> dp[1001][1001];
mint<MOD> solve(int n, int m){
    if(n < 0) return 0;
    if(m == B+1){
        if(n == 0) return 1;
        else return 0;
    }
    if(vis[n][m]) return dp[n][m];
  	vis[n][m] = true;
    mint<MOD> ret = solve(n, m+1);
    if(n < C*m) return dp[n][m] = ret;
    mint<MOD> tmp = 1;
    rep(i, C) tmp *= comb.C(n-m*i, m);
    for(int i=C; i<=D; i++){
        ret += solve(n-m*i, m+1)*tmp/comb.P(i, i);
        if(n-m*i < m) break;
        tmp *= comb.C(n-m*i, m);
    }
    return dp[n][m] = ret;
}

signed main(){
    cin >> N >> A >> B >> C >> D;
    comb.init(N);
    cout << solve(N, A) << endl;
}
