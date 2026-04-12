#include<bits/stdc++.h>
using namespace std;
using ll = long long;
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
#include<unordered_map>
#include <numeric>
#include<string_view>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(i) i.begin(),i.end()
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

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;
void c(){
   ll N; cin >> N;
   auto A = v<>(N,0);
   rep(i,N) cin >> A[i];
   sort(all(A));
   deque<ll> dq1;
   deque<ll> dq2;

    auto itf = A.begin();
    auto itb = A.end()-1;

    rep(i,N){
        if(i%4==0)dq1.push_back(*itb--);
        else if(i%4==1)dq1.push_front(*itf++);
        else if(i%4==2)dq1.push_front(*itb--);
        else if(i%4==3)dq1.push_back(*itf++);
    }

    itf = A.begin();
    itb = A.end()-1;

    rep(i,N){
        if(i%4==0)dq2.push_front(*itf++);
        else if(i%4==1)dq2.push_back(*itb--);
        else if(i%4==2)dq2.push_back(*itf++);
        else if(i%4==3)dq2.push_front(*itb--);
    }

    ll sum1 = 0;
    ll sum2 = 0;

    rep(i,N-1){
        sum1+=abs(dq1[i]-dq1[i+1]);
        sum2+=abs(dq2[i]-dq2[i+1]);
    }

    cout << max(sum1,sum2) << endl;

}
int main(void){
    c();
    return 0;
 }