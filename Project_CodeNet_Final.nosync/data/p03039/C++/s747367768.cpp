#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#ifdef DEBUG
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
#else
#define show(...) 42
#endif
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a) {
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> v) {
    for (auto x : v) os << x << ' ';
    return os;
}
void debug() {
    cerr << '\n';
}
template <typename H, typename... T>
void debug(H a, T... b) {
    cerr << a;
    if (sizeof...(b)) cerr << ", ";
    debug(b...);
}
template<int MOD>
class Modint{
public:
    int a;
    Modint(const long long v = 0):a(v % MOD){}
    int getmod() const{
        return MOD;
    }
    Modint operator+(const Modint rhs) const{
        return Modint(*this) += rhs;
    }
    Modint operator-(const Modint rhs) const{
        return Modint(*this) -= rhs;
    }
    Modint operator*(const Modint rhs) const{
        return Modint(*this) *= rhs;
    }
    Modint operator/(const Modint rhs) const{
        return Modint(*this) /= rhs;
    }
    Modint operator+(const long long rhs) const{
        return Modint(*this) += rhs;
    }
    Modint operator-(const long long rhs) const{
        return Modint(*this) -= rhs;
    }
    Modint operator*(const long long rhs) const{
        return Modint(*this) *= rhs;
    }
    Modint operator/(const long long rhs) const{
        return Modint(*this) /= rhs;
    }
    friend Modint operator+(const long long a, const Modint b){
        return b + a;
    }
    friend Modint operator-(const long long a, const Modint b){
        return -b + a;
    }
    friend Modint operator*(const long long a, const Modint b){
        return b * a;
    }
    friend Modint operator/(const long long a, const Modint b){
        return Modint(a) / b;
    }
    Modint &operator+=(const Modint rhs){
        a += rhs.a;
        if(a >= MOD){
            a -= MOD;
        }
        return *this;
    }
    Modint &operator-=(const Modint rhs){
        if(a < rhs.a){
            a += MOD;
        }
        a -= rhs.a;
        return *this;
    }
    Modint &operator*=(const Modint rhs){
        a = (long long)a * rhs.a % MOD;
        return *this;
    }
    Modint &operator/=(Modint rhs){
        int x = MOD - 2;
        while(x){
            if(x % 2){
                *this *= rhs;
            }
            rhs *= rhs;
            x /= 2;
        }
        return *this;
    }
    Modint &operator++(){
        *this += 1;
        return *this;
    }
    Modint &operator--(){
        *this -= 1;
        return *this;
    }
    Modint operator++(int){
        Modint res = *this;
        ++(*this);
        return res;
    }
    Modint operator--(int){
        Modint res = *this;
        res -= 1;
        return res;
    }
    Modint &operator+=(const long long rhs){
        *this += Modint(rhs);
        return *this;
    }
    Modint &operator-=(const long long rhs){
        *this -= Modint(rhs);
        return *this;
    }
    Modint &operator*=(const long long rhs){
        *this *= Modint(rhs);
        return *this;
    }
    Modint &operator/=(const long long rhs){
        *this /= Modint(rhs);
        return *this;
    }
    Modint operator+() const{
        return *this;
    }
    Modint operator-() const{
        return Modint()-*this;
    }
    bool operator==(const Modint rhs) const{
        return a == rhs.a;
    }
    bool operator==(const long long rhs) const{
        return a == rhs;
    }
    friend bool operator==(const long long a, const Modint b){
        return a == b.a;
    }
    bool operator!=(const Modint rhs) const{
        return a != rhs.a;
    }
    bool operator!=(const long long rhs) const{
        return a != rhs;
    }
    friend ostream &operator<<(ostream &os, const Modint x){
        os << x.a;
        return os;
    }
    friend istream &operator>>(istream &is, Modint &x){
        is >> x.a;
        return is;
    }
    explicit operator bool() const{
        return a > 0;
    }
    bool operator!(){
        return a == 0;
    }
    explicit operator int() const{
        return a;
    }
    explicit operator long long() const{
        return (long long) a;
    }
    friend Modint pow(Modint a, long long b){
        Modint res = 1;
        while(b){
            if(b % 2){
                res *= a;
            }
            a *= a;
            b /= 2;
        }
        return res;
    }
};
using mint = Modint<1000000007>;
const int NUM = 400005;
mint fact[NUM], fact_inv[NUM], inv[NUM];
mint combi(long long N_, long long K_){
    static const int Mod_ = fact[0].getmod();
    if(fact[0] == 0){
        inv[1] = fact[0] = fact_inv[0] = 1;
        for(int i = 2; i <= NUM; i++){
            inv[i] = inv[Mod_ % i] * (Mod_ - Mod_ / i);
        }
        for(int i = 1; i <= NUM; i++){
            fact[i] = fact[i - 1] * i;
            fact_inv[i] = fact_inv[i - 1] * inv[i];
        }
    }
    if(K_ < 0 or K_ > N_) return 0;
    return fact_inv[K_] * fact[N_] * fact_inv[N_ - K_];
}
mint hcomb(long long N_, long long K_){
    return ((N_ | K_) == 0) ? 1 : combi(N_ + K_ - 1, K_);
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    mint ans = 0;
    rep(i,n+1)ans += mint(1)*(n-i)*i*m*m;
    swap(n,m);
    rep(i,n+1)ans += mint(1)*(n-i)*i*m*m;
    ans *= combi(n*m-2,k-2);
    cout << ans << endl;
}