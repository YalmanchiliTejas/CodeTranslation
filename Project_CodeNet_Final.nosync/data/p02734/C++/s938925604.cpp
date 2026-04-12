#include <bits/stdc++.h>
#define ll long long
#define V vector<long long>
#define VV vector<vector<long long>>
#define VVV vector<vector<vector<long long>>>
#define P pair<ll,ll>
#define rep(i,n) for(ll (i)=0;(i)<(n);++(i))
using namespace std;

long long mod=998244353;
struct mint{
    long long x;
    mint(long long x=0):x((x%mod+mod)%mod){}
    mint operator-() const{return mint(-x);}
    mint& operator+=(const mint a){
        if((x+=a.x)>=mod)x-=mod;
        return *this;
    }
    mint& operator-=(const mint a){
        if((x+=mod-a.x)>=mod)x-=mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x*=a.x)%=mod;
        return *this;
    }
    mint operator+(const mint a)const{return mint(*this)+=a;}
    mint operator-(const mint a)const{return mint(*this)-=a;}
    mint operator*(const mint a)const{return mint(*this)*=a;}
    mint pow(long long t)const{
        if(!t)return 1;
        mint a=pow(t>>1);
        a*=a;
        if(t&1)a*=*this;
        return a;
    }
    mint inv()const{return pow(mod-2);}
    mint& operator/=(const mint a){return *this*=a.inv();}
    mint operator/(const mint a)const{return mint(*this)/=a;}
};
istream& operator>>(istream& is,mint& a){return is>>a.x;}
ostream& operator<<(ostream& os,const mint& a){return os<<a.x;}

int main() {
    ll n,s;
    cin>>n>>s;
    V a(n);
    rep(i,n)cin>>a[i];
    vector<vector<mint>> dp(n+1,vector<mint>(s+1,0));
    mint ans=0;
    rep(i,n){
        dp[i][0]+=1;
        rep(j,s+1){
            dp[i+1][j]+=dp[i][j];
            if(j+a[i]<=s)dp[i+1][j+a[i]]+=dp[i][j];
        }
        ans+=dp[i+1][s];
    }
    cout<<ans<<endl;
}
