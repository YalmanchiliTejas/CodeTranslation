#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

struct modint{
    using i64=int_fast64_t;
    i64 a;
    static constexpr i64 MOD=998244353;
    modint(){a=0;}
    modint(i64 a_){
        a=a_%MOD;
        if(a<0) a+=MOD;
    }
    modint inv()const{
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
    bool operator==(const modint& x){
        return a==x.a;
    }
    bool operator!=(const modint& x){
        return a!=x.a;
    }
    modint& operator=(const modint& x){
        a=x.a;
        return *this;
    }
    modint operator+(const modint& x){
        modint y;
        y.a=a+x.a;
        if(y.a>=MOD) y.a-=MOD;
        return y;
    }
    modint operator-(const modint& x){
        modint y;
        y.a=a-x.a;
        if(y.a<0) y.a+=MOD;
        return y;
    }
    modint operator*(const modint& x){
        modint y;
        y.a=(a*x.a)%MOD;
        return y;
    }
    modint operator/(const modint& x){
        modint y;
        y.a=(a*x.inv().a)%MOD;
        return y;
    }
    modint& operator+=(const modint& x){
        a+=x.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    modint& operator-=(const modint& x){
        a-=x.a;
        if(a<0) a+=MOD;
        return *this;
    }
    modint& operator*=(const modint& x){
        (a*=x.a)%=MOD;
        return *this;
    }
    modint& operator/=(const modint& x){
        (a*=x.inv().a)%=MOD;
        return *this;
    }
};
istream& operator>>(istream &in,modint& x){
    int_fast64_t a_;
    in>>a_;
    modint y(a_);
    x=y;
    return in;
}
ostream& operator<<(ostream &out,const modint& x){
    out<<x.a;
    return out;
}
modint pwr(int_fast64_t a,int_fast64_t b){
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    istream& in(cin);
    ostream& out(cout);
    int n,s;
    in>>n>>s;
    vector<int> a(n);
    fr(i,n) in>>a[i];
    vector<modint> dp(s+1);
    modint ans{};
    dp[0]=1;
    fr(i,n){
        if(a[i]<=s){
            for(int j=s;j>a[i];--j) dp[j]+=dp[j-a[i]];
            dp[a[i]]+=i+1;
            ans+=dp[s]*(n-i);
            dp[s]=0;
        }
    }
    cout<<ans<<endl;
}