#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1e9+7;


ll powm(ll x,ll k){
    ll res=1;
    while(k){
        if(k&1) res*=x;
        k>>=1;
        x*=x;
        res%=MOD;
        x%=MOD;
    }
    return res;
}

vector<vector<ll>> patp;
vector<vector<ll>> pati;

ll query_p(int hei,int l,int r,vector<ll>& h){
    if(patp[l][r]!=-1){
        return patp[l][r];
    }
    if(l==r) return 1;
    ll mi=1e9;
    for(int i=l;i<r;i++){
        mi=min(mi,h[i]);
    }
    int tail=l;
    ll res=powm(2,mi-hei); //todo
    for(int i=l;i<=r;i++){
        if(i==r || h[i]==mi){
            res*=query_p(mi,tail,i,h);
            res%=MOD;
            tail=i+1;
        }
    }
    return patp[l][r]=res;
}

ll query_i(int hei,int l,int r,vector<ll>& h){
    if(pati[l][r]!=-1){
        return pati[l][r];
    }
    if(l==r) return 0;
    ll mi=1e9;
    ll cnt=1;
    for(int i=l;i<r;i++){
        if(h[i]<mi){
            mi=h[i];
            cnt=1;
        }
        else if(h[i]==mi){
            cnt++;
        }
    }
    int tail=l;
    ll res=powm(2,cnt);
    for(int i=l;i<=r;i++){
        if(i==r || h[i]==mi){
            ll v=query_p(mi,tail,i,h);
            if(v!=1){
                res*=(query_i(mi,tail,i,h)%MOD+2*v)%MOD;
            }
            else{
                res*=(query_i(mi,tail,i,h)%MOD+v)%MOD;
            }
            res%=MOD;
            tail=i+1;
        }
    }
    
    res=((res-(2*query_p(hei,l,r,h))*powm(powm(2,mi-hei),MOD-2))%MOD%MOD+MOD)%MOD;
    
    return pati[l][r]=res;
}
int main(){
    int n;
    cin>>n;
    patp.assign(n+1,vector<ll>(n+1,-1));
    pati.assign(n+1,vector<ll>(n+1,-1));
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    ll num=(2*query_p(1,0,n,h)+query_i(1,0,n,h))%MOD;
    cout<<num<<endl;
    return 0;
}