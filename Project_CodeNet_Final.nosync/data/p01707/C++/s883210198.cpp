#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<pii,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-7;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
ll dp[2020][2020];
//nCr mod m
#define MOD 1000000007
#define M 1000000
vector<ll> fact;
bool h=false;
void init(){
    h=true;
    fact=vector<ll>(M);
    fact[0]=fact[1]=1;
    loop(i,2,M)fact[i]=fact[i-1]*i%MOD;
}
// a^b mod MOD
ll powmod(ll a,ll b,ll m){
    ll out=1;
    ll p=a%m;
    while(b){
        if(b&1)out=out*p%m;
        p=p*p%m;
        b>>=1;
    }
    return out;
}
int main(){
    ll n,d,x;
    while(cin>>n>>d>>x,x){
        rep(i,2020)rep(j,2020)dp[i][j]=0;
        dp[0][0]=1;
        rep(i,n)rep(j,n){
            ll t=(dp[i+1][j]+dp[i][j])%MOD;
            if(j+1-x>=0)(t+=MOD-dp[i][j+1-x])%=MOD;
            dp[i+1][j+1]=t;
        }
//      rep(i,n+1){rep(j,n+1)cout<<" "<<dp[i][j];cout<<endl;}
        ll out=0;
        ll q=1;
        ll N=min(n,d);
        rep(i,N+1){
            ll t=dp[i][n]*q%MOD;
            (q*=(d-i)%MOD*powmod(i+1,MOD-2,MOD)%MOD)%=MOD;
            (out+=t)%=MOD;
        }
        cout<<out<<endl;
    }
}