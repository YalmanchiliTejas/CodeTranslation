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
void a(){
   ll D,T,S;
   cin >> D >> T >> S;
   if(D<=T*S){
       cout << "Yes" << endl;
   }else{
       cout << "No" << endl;
   }
}

void b(){
   string S,T; cin >> S >> T;
   ll ans = 0;
   for(ll i=0;i<S.size()-T.size();i++){
       ll cnt = 0;
       for(ll j=0;j<T.size();j++){
           if(S[i+j]==T[j])cnt++;
       }
       chmax(ans,cnt);
   }
   cout << T.size()-ans << endl;
}

void c(){
    ll N; cin >> N;
    auto A = v<mint>(N,0);
    rep(i,N) cin >> A[i];
    mint ans=0;
    mint sum = 0;
    rep(i,N) sum+=A[i];
  
    for(ll i = N-1;i>=0;i--){
        ans+=(sum-A[i])*A[i];
    }
    cout << ans/2 << endl;
}


void d(){
     
}

void e(){

}

int main(void){
    c();
    return 0;
 }