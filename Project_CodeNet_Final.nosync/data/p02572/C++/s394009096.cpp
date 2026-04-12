#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define Clear(a) a = decltype(a)()
#define all(a) a.begin(),a.end()
#define vec vector
typedef long long ll;
typedef pair<ll,ll> P;
//const ll big=998244353;
const ll big=1000000007LL;
const ll INF=1e18;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
if(x<y)return x;
else return y;
}
ll expm(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (expm(x,y-1)*x)%big;
    ll t=expm(x,y/2);
    return (t*t)%big;
}
ll exp(ll x,ll y){
    if(y==0)return 1;//0^0=1
    if(x==1||y==0)return x;
    if(y%2==1)return exp(x,y-1)*x;
    ll t=exp(x,y/2);
    return t*t;
}
ll inv(ll x){
    return expm(x,big-2);
}

struct mint{
    ll x;
    constexpr mint(ll x=0) noexcept : x ((x%big+big)%big){}
    constexpr mint operator-() const noexcept{
        return mint(-x);
    }
    constexpr mint& operator+=(const mint &a) noexcept{
        if((x+=a.x)>=big)x-=big;
        return *this;
    }
    constexpr mint& operator-=(const mint &a) noexcept{
        if((x+=big-a.x)>=big)x-=big;
        return *this;
    }
    constexpr mint& operator*=(const mint &a) noexcept{
        (x*=a.x)%=big;
        return *this;
    }
    constexpr mint& operator/=(const mint &a) noexcept{
        return (*this)*=a.inv();
    }
    constexpr mint& operator++() noexcept{
        (*this)+=1;
        return (*this);
    }
    constexpr mint& operator--() noexcept{
        (*this)-=1;
        return (*this);
    }
 
    constexpr mint operator+(const mint &a)const noexcept{
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint &a)const noexcept{
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint &a)const noexcept{
        mint res(*this);
        return res*=a;
    }
    constexpr mint operator/(const mint &a)const noexcept{
        mint res(*this);
        return res/=a;
    }
    
    constexpr bool operator==(const mint &a)const noexcept{
        if((*this).x==a.x)return true;
        else return false;
    }
    constexpr bool operator!=(const mint &a)const noexcept{
        return !((*this)==a);
    }
    constexpr bool operator<(const mint &a)const noexcept{
        if((*this).x<a.x)return true;
        else return false;
    }
    constexpr bool operator>(const mint &a)const noexcept{
        if((*this).x>a.x)return true;
        else return false;
    }
    constexpr bool operator<=(const mint &a) noexcept{
        return !((*this)>a);
    }
    constexpr bool operator>=(const mint &a) noexcept{
        return !((*this)<a);
    }
 
    constexpr mint pow(ll t)const noexcept{
        if(t==0)return (mint)1;
        if(t%2==0){
            mint k=pow(t/2);
            return k*k;
        }else{
            if(t>0)return (*this)*pow(t-1);
            else return pow(t+1)/(*this);
        }
    }
    constexpr mint inv()const noexcept{
        return (mint)forinv((*this).x,big).first;
    }
 
    friend ostream& operator<<(ostream &os,const mint &m)noexcept{
        os << m.x;
        return os;
    }
    friend istream& operator>>(istream &is,mint &m)noexcept{
        is >> m.x;
        m.x=(m.x%big+big)%big;
        return is;
    }
 
private:
    constexpr pair<ll,ll> forinv(ll a,ll b)const noexcept{
        if(b==0)return pair<ll,ll>(1,0);
 
        pair<ll,ll> ans = forinv(b,a%b);
        pair<ll,ll> t=pair<ll,ll>(ans.second,ans.first-a/b*ans.second);
        return t;
    }
};
 
mint com(ll x,ll y){
    if(y>x||y<0)return 0;
    mint ans=1;
    rep(i,y){
        mint t=x-i,s=y-i;
        ans*=t/s;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout << fixed << setprecision(10);
    /*--------------------------------*/

    int n;cin >> n;
    vec<mint> a(n);
    rep(i,n)cin >> a[i];
    mint ans=0;
    mint wa=0;
    rep(i,n){
        wa+=a[i];
        ans-=a[i]*a[i];
    }
    ans+=wa*wa;
    cout << ans/2 << endl;
}