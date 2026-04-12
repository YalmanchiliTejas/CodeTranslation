#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

const int MAX=510000;

vll fac(MAX);
vll finv(MAX);
vll inv(MAX);

void combinit(ll m){
    fac[0]=1;fac[1]=1;
    finv[0]=1;finv[1]=1;
    inv[1]=1;
    rep2(i,2,MAX){
        fac[i]=fac[i-1]*i%m;
        inv[i]=m-inv[m%i]*(m/i)%m;
        finv[i]=finv[i-1]*inv[i]%m;
    }
}

ll combi(ll n,ll k,ll m=inf){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%m)%m;
}

ll calculate(ll x,ll y,ll k){
    ll sum=(ll)0,res,tmp;
    for(ll i=1;i<x;i++){
        res=i;res*=(x-i);
        res%=inf;
        res*=y*y;
        res%=inf;
        tmp=x*y-(ll)2;
        tmp%=inf;
        res*=combi(tmp,k-(ll)2);//ペアを一組決めた状態
        res%=inf;
        sum+=res;
    }
    return sum;
}

int main(){
    ll n,m,k;cin>>n>>m>>k;
    combinit(inf);
    ll ans=calculate(n,m,k)+calculate(m,n,k);
    ans%=inf;
    cout<<ans<<endl;
}