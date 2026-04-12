#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;

#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)
 
const ll MOD=1e9+7;

//足し算してmodをとる
ll ad(ll x,ll y=0){
    return (x+y)%MOD;
}

//mod _mult 
ll mlt(ll x,ll y=1){
    return (x*y)%MOD;
}

 //xのy条
ll pwr(ll x,ll n){
    ll v=1;
    while(n>0){
      if (n%2==1) v=mlt(v, x);
      x=mlt(x,x);
      n/=2;
    }
    return v;
}

 //フェルマーの小定理に夜と、　x^(mod-2)=-1
ll inv(ll x){
    return pwr(x,MOD-2);
}

 //factorial
ll fc[200010]={1};
ll fct(ll x){
    if(fc[x]==0) fc[x]=mlt(x,fct(x-1));
    return fc[x];
}

 //inverse_factorial
ll ifc[200010]={1};
ll ifct(ll x){
    if(ifc[x]==0) ifc[x]=inv(fct(x));
    return ifc[x];
}
 
ll comb(ll n,ll r){
    if(n<0 || r<0 || n<r) return 0;
    return mlt(fct(n),mlt(ifct(r),ifct(n-r)));
}
 
int main(){
    ll n,a,b,c,d,f;
    cin>>n>>a>>b>>c>>d;
    ll dp[1010][1010]={};
    fct(1010);
    ifct(1010);
    ifr(i,1010){
        ifc[i]=mlt(i+1,ifc[i+1]);
    }
    dp[b+1][n]=1;
    for(ll i=b;i>=a;i--){
        //cout << i << endl;
        fr(j,n+1){
            dp[i][j]=ad(dp[i][j],dp[i+1][j]);
            f=1;
            Fr(k,c-1) f=mlt(f,comb(j+k*i,i));
            for(ll k=c;k<=d;k++){
                if(j+i*k>n) break;
                f=mlt(f,comb(j+k*i,i));
                dp[i][j]=ad(dp[i][j],mlt(dp[i+1][j+i*k],mlt(f,ifct(k))));
            }
        }
    }
    /*for(int i=2;i<4;i++){
        fr(j,8) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[a][0]<<endl;
}