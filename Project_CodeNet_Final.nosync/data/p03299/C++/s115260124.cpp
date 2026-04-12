#include<iomanip>
#include<limits>
#include<thread>
#include<utility>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<numeric>
#include<cassert>
#include<random>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<fstream>
#include<list>
#include<functional>
#include<bitset>
#include<complex>
#include<tuple>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pi;
typedef pair<double,double> pd;
typedef pair<double,ll> pdl;
#define F first
#define S second
const ll E=1e18+7;
const ll MOD=1000000007;

ll n;
vector<ll> a;
const ll inv=(MOD+1)/2;

ll mod_pow(ll a,ll x){
    ll ret=1;
    while(x>0){
        if(x&1){(ret*=a)%=MOD;}
        (a*=a)%=MOD;
        x>>=1;
    }
    return ret;
}

pll search(ll l,ll r,ll h){
    pll ret={1,1}; //tate,yoko
    ll mx=0;
    ll mi=E;
    for(ll i=l;i<r;i++){
        mx=max(mx,a[i]-h);
        mi=min(mi,a[i]-h);
    }
    if(r-l==1){return {0,mod_pow(2,mx)};}
    if(mi==mx){return {mod_pow(2,r-l-1),mod_pow(2,mx)};}
    ll L=l;
    ll cnt=0;
    for(ll i=l;i<=r;i++){
        if(i==r || a[i]==mi+h){
            if(L<i){
                pll A=search(L,i,mi+h);
                (ret.S*=A.S)%=MOD;
                (ret.S*=inv)%=MOD;
                (ret.F*=(A.F+A.S*2)%MOD)%=MOD;
            }
            L=i+1;
            if(i!=r){cnt++;}
        }
    }
    (ret.F*=mod_pow(2,cnt))%=MOD;
    (ret.F-=ret.S*4)%=MOD;
    (ret.S*=mod_pow(2,mi))%=MOD;
    (ret.S*=2)%=MOD;
    cout<<l<<" "<<r<<" "<<h<<" "<<ret.F<<" "<<ret.S<<endl;
    return ret;
}

pll search2(ll l,ll r,ll h){
    pll ret={1,1}; //tate,yoko
    ll mx=0;
    ll mi=E;
    for(ll i=l;i<r;i++){
        mx=max(mx,a[i]-h);
        mi=min(mi,a[i]-h);
    }
    if(mi==mx){return {mod_pow(2,r-l)-2,mod_pow(2,mx)};}
    ll L=l;
    ll cnt=0;
    ll k2=1;
    for(ll i=l;i<=r;i++){
        if(i==r || a[i]==mi+h){
            if(L<i){
                pll A=search2(L,i,mi+h);
                (ret.S*=A.S)%=MOD;
                (ret.F*=(A.F+A.S*2)%MOD)%=MOD;
                (k2*=A.S)%=MOD;
            }
            L=i+1;
            if(i!=r){cnt++;}
        }
    }
    (ret.S*=mod_pow(2,mi))%=MOD;
    (ret.F*=mod_pow(2,cnt))%=MOD;
    (ret.F-=k2*2)%=MOD;
    //cout<<l<<" "<<r<<" "<<h<<" "<<ret.F<<" "<<ret.S<<endl;
    return ret;
}



int main(){
    cin>>n;
    a.resize(n);
    for(auto &I:a){cin>>I;}
    pll ans=search2(0,n,0);
    ll A=ans.F+ans.S;
    A%=MOD;
    if(A<0){A+=MOD;}
    cout<<A<<endl;
    
    
    return 0;
}
