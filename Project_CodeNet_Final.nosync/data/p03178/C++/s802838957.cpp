#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct mint{
    static const long long MOD = 1000000007;

    long long v;

    mint() : v(0) {}
    mint(long long x){
        x = x % MOD;
        if(x < 0){ x += MOD; }
        v = x;
    }
    mint& operator+=(mint a){
        v += a.v;
        if(v >= MOD){ v -= MOD; }
        return *this;
    }
    mint& operator*=(mint a){
        v *= a.v;
        v %= MOD;
        return *this;
    }
    mint& operator-=(mint a){
        v -= a.v;
        if(v < 0){ v += MOD; }
        return *this;
    }
    mint& operator/=(mint a){
        return (*this) *= a.inv();
    }

    mint operator*(mint a) const{
        return mint(v) *= a;
    }

    mint operator+(mint a) const {
        return mint(v) += a;
    }

    mint operator-(mint a) const {
        return mint(v) -= a;
    }

    mint operator/(mint a) const {
        return mint(v) /= a;
    }

    mint pow(long long k) const {
        mint res(1),tmp(v);
        while(k){
            if(k&1) res *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return res;
    }
    mint inv(){return pow(MOD - 2); }

    static mint comb(long long n, int k){
        mint res(1);
        for(int i = 0; i < k; ++i){
            res *= mint(n - i);
            res /= mint(i + 1);
        }
        return res;
    }

    static mint factorial(long long n){
        mint res(1);
        for(int i = n; i > 1; --i){
            res *= mint(i);
        }
        return res;
    }

    bool operator<(const mint &a) const {
        return v < a.v;
    };
};

mint operator*(long long l, mint r){ return r * l; }

std::ostream& operator<<(std::ostream& stream, const mint& m){
    stream << m.v;
    return stream;
}

int main(){
    string k;
    ll d;
    cin >> k >> d;
    vector<mint> dp(d, 0);

    for(int i = 0; i < k.at(0) - '0'; ++i){
        dp.at(i % d) += 1;
    }
    ll top = (k.at(0) - '0') % d;

    for(int i = 1; i < k.size(); ++i){
        vector<mint> dp2(d, 0);
        for(int j = 0; j < d; ++j){
            for(int x = 0; x <= 9; ++x){
                dp2.at((j + x) % d) += dp.at(j);
            }
        }
        for(int x = 0; x < k.at(i) - '0'; ++x){
            dp2.at((top + x) % d) += 1;
        }
        top = (top + (k.at(i) - '0')) % d;
        dp.swap(dp2);
    }
    cout << dp.at(0) + (top == 0) - 1 << endl;
    return 0;
}