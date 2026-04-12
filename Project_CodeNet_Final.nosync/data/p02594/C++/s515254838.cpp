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
    ll X; cin >> X;
    if(X>=30){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

void b(){
    ll N,D; cin >> N >> D;
    auto X = v<>(N,0);
    auto Y = v<>(N,0);
    rep(i,N) cin >> X[i] >> Y[i];
    ll cnt = 0;
    rep(i,N){
       cnt += (sqrt(X[i]*X[i]+Y[i]*Y[i])<=D)? 1:0;
    }
    cout << cnt << endl;
}

ll div(string C,string R){
    if(C.size()<=R.size()){
        return stoll(C)%stoll(R);
    }

    ll Cnum = stoll(C.substr(0,R.size()));
    ll Rnum = stoll(R);
    bool p = false;
    if(Cnum<Rnum){
        Cnum = stoll(C.substr(0,R.size()+1));
        p=true;
    }
    ll A = Cnum%Rnum;
    string CC = to_string(A) + C.substr(R.size()+(size_t)p);
    return div(CC,R);
}

void c(){
   ll K; cin >> K;
   if(K%2==0){
       cout << -1 << endl;
       return;
   }
   ll cnt = 1;
   ll N = 7%K;
   rep(i,K){
       if(N==0){
           cout << cnt << endl;
           return;
       }
       N=N*10+7;
       N%=K;
       cnt++;
   }
   cout << -1 << endl;
   return;
}

void d(){
    ll N; cin >> N;
    string S; cin >> S;
    priority_queue<ll,v<>,greater<ll>> W;
    priority_queue<ll> R;
    ll Wcnt = 0;
    ll Rcnt = 0;
    rep(i,N){
        if(S[i]=='W'){
            Wcnt++;
            W.push(i);
        }else{
            Rcnt++;
            R.push(i);
        }
    }

    ll cnt = 0;
    while(!W.empty()&&!R.empty()&&W.top()<R.top()){
        ll w = W.top(); W.pop();
        ll r = R.top(); R.pop();
        W.push(r);
        R.push(w);
        cnt++;      
    }
    cout << min({cnt,Wcnt,Rcnt});

}

void e(){
    ll N,K; cin >> N >> K;
    priority_queue<ll> A;
    rep(i,N) {
        ll t;
        cin >> t;
        A.push(t);
    }

    rep(i,K){
        ll t = A.top(); A.pop();
        A.push(t/2);
        A.push((t+1)/2);
    }

    cout << A.top() << endl;
} 

int main(void){
    a();
    return 0;
 }