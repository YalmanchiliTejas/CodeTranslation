#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)

const ll MOD=1e9+7;

//足し算してmodをとる
ll ad(ll x,ll y=0){
    return (x+y)%MOD;
}

//mod _mult
ll mlt(ll x,ll y){
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
ll fc[200010];
void fct(){
    fc[0]=1;
    for (int i=0;i<200009;++i){
      fc[i+1]=mlt(fc[i], i+1);
    }
}

 //inverse_factorial
ll ifc[200010];
void ifct(){
    ifc[200009]=inv(fc[200009]);
    for (int i=200009;i>=1;--i) ifc[i-1]=mlt(ifc[i], i);
}

ll comb(ll n,ll r){
    if(n<0 || r<0 || n<r) return 0;
    return mlt(fc[n],mlt(ifc[r],ifc[n-r]));
}

int main(){
    ll n,a,b,c,d,f;
    cin>>n>>a>>b>>c>>d;
    ll dp[1010][1010]={};
    fct();
    ifct();
    
    dp[b+1][n]=1;
    for(ll i=b;i>=a;i--){
        //cout << i << endl;
        for(int j=0;j<n+1;++j){
            dp[i][j]=ad(dp[i][j],dp[i+1][j]);
            f=1;
            for(int k=0;k++<c-1;) f=mlt(f,comb(j+k*i,i));
            for(ll k=c;k<=d;k++){
                if(j+i*k>n) break;
                f=mlt(f,comb(j+k*i,i));
                dp[i][j]=ad(dp[i][j],mlt(dp[i+1][j+i*k],mlt(f,ifc[k])));
            }
        }
    }
    /*for(int i=2;i<4;i++){
        fr(j,8) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[a][0]<<endl;
}
