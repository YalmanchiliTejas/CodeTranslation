#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)

struct modint{
    ll a;
    const ll MOD=1e9+7;
    modint(ll a_=0){
        a=((a_%MOD)+MOD)%MOD;
    }
    modint inv()const{
        ll n=1,m=MOD-2,A=a;
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
    modint& operator=(const modint& x){
        a=x.a;
        return *this;
    }
    modint operator+(const modint& x){
        modint y(a+x.a);
        return y;
    }
    modint operator-(const modint& x){
        modint y(a-x.a);
        return y;
    }
    modint operator*(const modint& x){
        modint y(a*x.a);
        return y;
    }
    modint operator/(const modint& x){
        return *this * x.inv();
    }
    modint& operator+=(const modint& x){
        *this=*this+x;
        return *this;
    }
    modint& operator-=(const modint& x){
        *this=*this-x;
        return *this;
    }
    modint& operator*=(const modint& x){
        *this=*this*x;
        return *this;
    }
    modint& operator/=(const modint& x){
        *this=*this/x;
        return *this;
    }
};
istream& operator>>(istream &in,modint& x){
    ll a_;
    in>>a_;
    modint y(a_);
    x=y;
    return in;
}
ostream& operator<<(ostream &out,const modint& x){
    out<<x.a;
    return out;
}
modint pwr(ll a,ll b){
    modint n(1),A(a);
    while(b){
        if(b&1) n*=A;
        A*=A;
        b>>=1;
    }
    return n;
}
modint fc[400010]={1};
modint fct(int n){
    if(fc[n].a) return fc[n];
    return fc[n]=modint(n)*fct(n-1);
}
modint ifc[400010]={1};
modint ifct(int n){
    if(fc[n].a) return ifc[n];
    return ifc[n]=modint(n).inv()*ifct(n-1);
}
void initfct(int n){
    ifct(n);
    ifr(i,n) ifc[i]=ifc[i+1]*(i+1);
}
modint cmb(int n,int r){
    if(n<0||r<0||n<r) return 0;
    return fct(n)*ifct(r)*ifct(n-r);
}

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    modint ans(1),c(n*m);
    ans=modint(6).inv()*(modint(n-1)*n*(n+1)*m*m+modint(m-1)*m*(m+1)*n*n);
    for(int i=3;i<=k;i++){
        ans*=(c-i+1)*modint(i-2).inv();
    }
    cout<<ans<<endl;
}