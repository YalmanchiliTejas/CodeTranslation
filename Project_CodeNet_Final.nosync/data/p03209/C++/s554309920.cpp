//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<cmath>
#include<map>
#include<functional>
#include<queue>
#include<set>
#include<stack>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<memory>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(a)   a.begin(),a.end()
template<typename T =ll> using v = vector<T>;
template<typename T =ll> using vv = v<v<T>>;
template<typename T =ll,typename U =ll> using p = pair<T,U>;
template<typename T> T chmin(T &a,T b) {return a=min(a,b);}
template<typename T> T chmax(T &a,T b) {return a=max(a,b);}
const ll INF = (ll)1e9;
template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }
    //
    ModInt operator++(int) {
        auto t = *this;
        *this += 1;
        return t;
    }

    ModInt operator--(int) {
        auto t = *this;
        *this -= 1;
        return t;
    }
    ModInt operator<<(const int n){
        return ModInt(*this)*ModInt(2).pow(n);
    }
    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;
ll N,X; 

class d{
    ll N,X;
    v<> A;
    v<> P;
    ll func(ll i,ll x){
        if(i==0) return x==1? 1 : 0;

        if(x<A[i-1]+2){
            return func(i-1,x-1);
        }else if(x==A[i-1]+2){
            return P[i-1]+1;
        }else if(x<2*A[i-1]+3){
            return func(i-1,x-A[i-1]-2)+P[i-1]+1;
        }else{
            return 2*P[i-1]+1;
        }
    }

    public:
    d(){
        cin >> N >>X;
        A.push_back(1);
        P.push_back(1);
        rep(i,N+1){
            A.push_back(2*A.back()+3);
            P.push_back(2*P.back()+1);
        }
        cout << func(N,X);
    }
};

int main(){
    d();
    return 0;
}