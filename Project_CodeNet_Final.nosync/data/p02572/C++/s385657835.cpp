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

int N;
mint<MOD> A[200000];

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];

    mint<MOD> sum = 0;
    mint<MOD> ans = 0;
    rep(i, N){
        ans += sum * A[i];
        sum += A[i];
    }
    cout << ans << endl;
}