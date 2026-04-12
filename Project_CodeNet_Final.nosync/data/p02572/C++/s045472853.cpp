#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()





//library mod int
template <int mod>
struct modint{
    ll x;

    //constructor
    modint(ll x=0): x((x%mod+mod)%mod){}

    //unary operator
    modint operator-() const { return modint(mod-x);}
    modint inv() const { return this->pow(mod-2);}
    
    //compound assignment
    modint& operator+=(const modint& a){
        if((x+=a.x)>=mod) x-=mod;
        return *this;
    }
    modint& operator-=(const modint& a){
        if((x-=a.x)<0) x+=mod;
        return *this;
    }
    modint& operator*=(const modint& a){
        (x*=a.x)%=mod;
        return *this;
    }
    modint& operator/=(const modint& a){
        return *this *= a.inv();
    }

    //arithmetic
    // なぜmodintの後ろに＆を書いたり書かなかったりしてるかの理解ができていない
    //おそらく＆をつけるとポインタで参照しているのでもとの値を書き換えることができる
    //＆をつけないとコピーを作ってからそれに対して計算するので、もとの値は変更されない
    modint operator-(const modint& a) const {return modint (*this) -= a ; }
    modint operator+(const modint& a) const {return modint (*this) += a ; }
    modint operator*(const modint& a) const {return modint (*this) *= a ; }
    modint operator/(const modint& a) const {return modint (*this) /= a ; }
    //n should not be smaller than 0.
    modint pow(ll n) const{
        auto x=modint(1);
        auto m=*this;
        while(n>0){
            if(n&1) x*=m;
            n>>=1;
            m*=m;
        }
        return x;
    }

    //compare
    bool operator==(const modint& a) const {return x==a.x ; }
    bool operator!=(const modint& a) const {return x!=a.x ; }

    //I/O
    friend istream& operator>>(istream& is, modint& a ) noexcept {return is >> a.x ; }
    friend ostream& operator<<(ostream& os, const modint& a ) noexcept {return os << a.x ; }
};

//modの調整
constexpr int mod = 1e9 + 7;
using mint = modint<mod>;

//////////////////////////////////////////////////////////////////////
//mint power
mint mpow(mint a, mint b){
    auto x=mint(1), m=a;
    auto n=b.x;
    while(n>0){
        if(n&1) x*=m;
        n>>=1;
        m*=m;
    }
    return x;
}

//combination
vector<mint> mintcombvector;
int startmintcomb(int n){
    mintcombvector.push_back(0);
    mintcombvector.push_back(1);
    rep(i,n) mintcombvector.push_back(mintcombvector[i+1]*(i+2));
    return 0;
}
mint comb(mint a, mint b){
    if(a.x<b.x || a.x<=0 || b.x<0) return mint(0);
    if(b.x==0) return mint(1);
    if(a==b) return mint(1);
    return mintcombvector[a.x]*(mintcombvector[b.x].inv())*(mintcombvector[a.x-b.x].inv());
}
//combinationを使いたいときは　startmintcomb(n=代入したい数の最大値); を始めに打つこと



int main(){
    int n; cin>>n;
    vector<mint> a(n);
    rep(i,n){
        cin>>a[i];
    }
    mint ans=0;
    vector<mint> p(n);
    p[0]=a[0];
    rep(i,n-1){
        p[i+1]=p[i]+a[i+1];
    }
    rep(i,n){
        ans+=a[i]*(p[n-1]-p[i]);
    }
    cout<<ans<<endl;
    return 0;
}