#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

void ModInv(int n, vector<ll> &inv, int mod){
    inv[0]=0; inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=mod-((mod/i)*inv[mod%i]%mod);
}

void FacInv(int n,vector<ll> inv,vector<ll> &fac,vector<ll> &facInv,int mod){
    fac[0]=facInv[0]=1;
    rep1(i,n){
        fac[i]=(fac[i-1]*i)%mod;
        facInv[i]=(facInv[i-1]*inv[i])%mod;
    }
}

ll CombIMod(int n,int k,int mod,const vector<ll> &inv,const vector<ll> &fac,const vector<ll> &facInv){
    if(n==0&&k==0) return 1;
    if(n<=0||k<0||k>n) return 0;
    if(k==0) return 1;
    return (((fac[n]*facInv[k])%mod)*facInv[n-k])%mod;
}

ll powMod(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin>>N>>M;
    
    vector<ll> inv(N+1);
    vector<ll> fac(N+1);
    vector<ll> facInv(N+1);
    ModInv(N,inv,M);
    FacInv(N,inv,fac,facInv,M);
    
    vector<ll> ways(N+1,0);
    vector<vector<ll>> ways2(N+1,vector<ll>(N+1,0));
    ways2[0][0]=1;
    rep1(i,N){
        rep(j,N+1){
            if(j>i){
                ways2[i][j]=0;
            }else if(j==0||j==i){
                ways2[i][j]=1;
            }else{
                ways2[i][j]=(((j+1)*ways2[i-1][j])%M+ways2[i-1][j-1])%M;
            }
        }
    }
    
    rep(i,N+1){
        rep(j,i+1){
            ways[i]+=ways2[i][j]*powMod(2,(ll)(N-i)*j,M);
            ways[i]%=M;
        }
        ways[i]*=powMod(2,powMod(2,N-i,M-1),M);
        ways[i]%=M;
    }
    
    ll ans=0;
    rep(i,N+1){
        ll val=(CombIMod(N,i,M,inv,fac,facInv)*ways[i])%M;
        
        if(i%2==0) ans=(ans+val)%M;
        else ans=(ans-val+M)%M;
    }
    cout1(ans);
}