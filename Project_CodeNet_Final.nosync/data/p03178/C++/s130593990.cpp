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
using P=pair<ll,ll>;
using PP=pair<ll,P>;
using vp=vector<P>;
using vpp=vector<PP>;
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

const int mod=1e9+7;
using mint=ModInt<mod>;
int main(){
    string st;
    cin>>st;
    int n=st.size();
    vi dig(n);
    REP(i,n){
        dig[i]=stoi(st.substr(i,1));
    }
    int d;
    cin>>d;
    mint dp[n+1][d][2];
    dp[0][0][1]=1;
    REP(i,n){
        REP(j,d){
            dp[i+1][(j+dig[i])%d][1]+=dp[i][j][1];
            REP(k,10){
                dp[i+1][(j+k)%d][0]+=dp[i][j][0];
                if(k<dig[i]){
                    dp[i+1][(j+k)%d][0]+=dp[i][j][1];
                }
            }
        }
    }
    cout<<dp[n][0][0]+dp[n][0][1]-1<<endl;
    return 0;
}