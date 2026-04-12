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
        modint y(n);
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
        if(y.a>MOD) y.a-=MOD;
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

template <int n> struct COMB{
    vector<int_fast64_t> fc,ifc;
    COMB():fc(n),ifc(n){
        fc[0]=1;
        for(int i=1;i<n;++i) fc[i]=fc[i-1]*i%modint::MOD;
        int_fast64_t N=1,A=fc[n-1],b=modint::MOD-2;
        while(b){
            if(b&1) (N*=A)%=modint::MOD;
            (A*=A)%=modint::MOD;
            b>>=1;
        }
        ifc[n-1]=N;
        for(int i=n-1;i>=1;--i) ifc[i-1]=ifc[i]*i%modint::MOD;
    };
    modint operator()(int N,int R)const{
        if(N<0||R<0||N<R) return 0;
        return fc[N]*ifc[R]%modint::MOD*ifc[N-R];
    }
    modint operator[](int N)const{
        modint _;
        _.a=fc[N];
        return _;
    }
    modint operator()(int N)const{
        modint _;
        _.a=ifc[N];
        return _;
    }
};
COMB<10000010> comb;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    istream& in(cin);
    ostream& out(cout);
    int n;
    in>>n;
    modint ans=pwr(3,n);
    fr(i,n/2) ans-=comb(n,i)*pwr(2,i+1);
    cout<<ans<<endl;
}