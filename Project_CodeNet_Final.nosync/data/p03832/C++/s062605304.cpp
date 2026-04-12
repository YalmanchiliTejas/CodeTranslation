#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) for(int i=(n);i>=0;i--)
#define all(vec) vec.begin(),vec.end()
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using P=pair<int,int>;
using PP=pair<int,P>;
using Pl=pair<ll,ll>;
using PPl=pair<ll,Pl>;
using vs=vector<string>;
#define fi first
#define se second
#define pb push_back
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(a>b){a=b;return true;}return false;}
const ll MOD=1000000007LL;
const int INF=1<<30;
const ll LINF=1LL<<60;
template<int mod>
struct ModInt{
    int x;
    ModInt():x(0){}
    ModInt(long long y):x(y>=0?y%mod:(mod-(-y)%mod)%mod){}
    ModInt &operator+=(const ModInt &p){
        if((x+=p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p){
        if((x+=mod-p.x)>=mod)x-=mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p){
        x=(int)(1LL*x*p.x%mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p){
        *this*=p.inverse();
        return *this;
    }
    ModInt operator-()const{return ModInt(-x);}
    ModInt operator+(const ModInt &p)const{return ModInt(*this)+=p;}
    ModInt operator-(const ModInt &p)const{return ModInt(*this)-=p;}
    ModInt operator*(const ModInt &p)const{return ModInt(*this)*=p;}
    ModInt operator/(const ModInt &p)const{return ModInt(*this)/=p;}
    bool operator==(const ModInt &p)const{return x==p.x;}
    bool operator!=(const ModInt &p)const{return x!=p.x;}
    ModInt inverse()const{
        int a=x,b=mod,u=1,v=0,t;
        while(b>0){
            t=a/b;
            a-=t*b;
            swap(a,b);
            u-=t*v;
            swap(u,v);
        }
        return ModInt(u);
    }
    friend ostream &operator<<(ostream &os,const ModInt<mod> &p){
        return os<<p.x;
    }
    friend istream &operator>>(istream &is,ModInt<mod> &a){
        long long x;
        is>>x;
        a=ModInt<mod>(x);
        return (is);
    }
};

template<int mod=1e9+7>
struct Combination{
    using mint=ModInt<mod>;
    vector<mint> fact;
    Combination(int n){
        n++;
        fact.resize(n);
        for(int i=0;i<n;i++){
            if(!i){
                fact[i]=1;
            }else{
                fact[i]=fact[i-1]*i;
            }
        }
    }
    mint Fact(int x){
        return fact[x];
    }
    mint Comb(int n,int r){
        return fact[n]/fact[r]/fact[n-r];
    }
};

const int mod=1e9+7;
using mint=ModInt<mod>;
int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    vector<vector<mint>> dp(n+2,vector<mint>(n+1));
    Combination<mod> C(n);
    dp[0][0]=1;
    REP(i,n+1){
        REP(j,n+1){
            //cerr<<dp[i][j]<<" ";
            dp[i+1][j]+=dp[i][j];
            if(i<a||b<i){
                continue;
            }
            if(j+i*c>n){
                continue;
            }
            mint now=1;
            REP(k,c-1){
                now*=C.Comb(n-j-k*i,i);
            }
            FOR(k,c,d+1){
                int x=k*i;
                if(j+x>n){
                    break;
                }
                now*=C.Comb(n-j-(k-1)*i,i);
                dp[i+1][j+x]+=dp[i][j]*now/C.Fact(k);
            }
        }
        //cerr<<endl;
    }
    cout<<dp[n+1][n]<<endl;
    return 0;
}