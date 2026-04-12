#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

struct modint{
    using i64=int_fast64_t;
    i64 a;
    static constexpr i64 MOD=1e9+7;
    constexpr modint():a(){}
    constexpr modint(i64 a_):a(a_%MOD){
        if(a<0) a+=MOD;
    }
    constexpr modint inv()const noexcept{
        i64 n=1,m=MOD-2,A=a;
        while(m){
            if(m&1)(n*=A)%=MOD;
            (A*=A)%=MOD;
            m>>=1;
        }
        modint y;
        y.a=n;
        return y;
    }
    constexpr modint operator+()noexcept{
        return *this;
    }
    constexpr modint operator-()noexcept{
        modint tmp{};
        if(a) tmp.a=MOD-a;
        return tmp;
    }
    constexpr modint& operator++()noexcept{
        ++a;
        if(a==MOD) a=0;
        return *this;
    }
    constexpr modint& operator--()noexcept{
        if(a) --a;
        else a=MOD-1;
        return *this;
    }
    constexpr modint operator++(int)noexcept{
        modint tmp=*this;
        ++a;
        if(a==MOD) a=0;
        return tmp;
    }
    constexpr modint operator--(int)noexcept{
        modint tmp=*this;
        if(a) --a;
        else a=MOD-1;
        return tmp;
    }
    constexpr bool operator==(const modint& x)const noexcept{
        return a==x.a;
    }
    constexpr bool operator!=(const modint& x)const noexcept{
        return a!=x.a;
    }
    constexpr modint operator+(const modint& x)const noexcept{
        modint y;
        y.a=a+x.a;
        if(y.a>=MOD) y.a-=MOD;
        return y;
    }
    constexpr modint operator-(const modint& x)const noexcept{
        modint y;
        y.a=a-x.a;
        if(y.a<0) y.a+=MOD;
        return y;
    }
    constexpr modint operator*(const modint& x)const noexcept{
        modint y;
        y.a=(a*x.a)%MOD;
        return y;
    }
    constexpr modint operator/(const modint& x)const noexcept{
        modint y;
        y.a=(a*x.inv().a)%MOD;
        return y;
    }
    constexpr modint& operator+=(const modint& x)noexcept{
        a+=x.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    constexpr modint& operator-=(const modint& x)noexcept{
        a-=x.a;
        if(a<0) a+=MOD;
        return *this;
    }
    constexpr modint& operator*=(const modint& x)noexcept{
        (a*=x.a)%=MOD;
        return *this;
    }
    constexpr modint& operator/=(const modint& x)noexcept{
        (a*=x.inv().a)%=MOD;
        return *this;
    }
};
istream& operator>>(istream &in,modint& x)noexcept{
    static int_fast64_t a_;
    in>>a_;
    modint y(a_);
    x=y;
    return in;
}
ostream& operator<<(ostream &out,const modint& x)noexcept{
    out<<x.a;
    return out;
}
constexpr modint pwr(int_fast64_t a,int_fast64_t b)noexcept{
    modint _;
    int_fast64_t n=1,A=a;
    while(b){
        if(b&1) (n*=A)%=modint::MOD;
        (A*=A)%=modint::MOD;
        b>>=1;
    }
    _.a=n;
    return _;
}

void solve(){
    int n;
    cin>>n;
    modint s,a,t;
    fr(i,n){
        cin>>a;
        s+=a;
        t+=a*a;
    }
    cout<<(s*s-t)/2<<'\n';
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t{1};
    //cin>>t;
    fr(i,t) solve();
}