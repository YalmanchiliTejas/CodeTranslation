#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};




vector<LL> fact;
vector<LL> inver(200001);
 
LL combi(int n,int r){
    if(n<r||n<0||r<0) return 0;
    return fact[n]%mod*inver[n-r]%mod*inver[r]%mod;
}
 
 
LL fpow(LL a, LL n){
    LL x = 1;
    while(n > 0){
        if(n&1){
            x=x*a%mod;
        }
        a=a*a%mod;
        n >>= 1;
    }
    return x;
}
 
void set_combi(){
    LL s=1;
    fact.push_back(1);
    for(int i=1;i<=200000;i++){
        s*=i;
        s%=mod;
        fact.push_back(s);
    }
    inver[200000]=fpow(fact[200000],mod-2);
    for(int i=199999;i>=0;i--){
        inver[i]=inver[i+1]*(i+1)%mod;
    }
}
 
LL hcombi(int n,int r){
    return combi(n+r-1,r); 
}
vector<LL> divi(LL K){
    vector<LL> v;
    for(int i=1;i*i<=K;i++){
        if(K%i) continue;
        v.pb(i);
        v.pb(K/i);
    }
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    return v;
}

vector<LL> pdivi(LL K){
    vector<LL> v;
    for(int i=2;i*i<=K;i++){
        if(K%i) continue;
        v.pb(i);
        while(K%i==0){
            K/=i;
        }
    }
    if(K!=1) v.pb(K);
    return v;
}





int main(){
    set_combi();
    int n,m,k;cin >> n >> m >> k;
    LL ans = 0;
    LL l=0,r=m-1;
    for (int i = 0; i < m; i++) {
        ans=(ans+n*n%mod*((i-l)*(i-l+1)/2+(r-i)*(r-i+1)/2))%mod;

    }
    r=n-1;
    for (int i = 0; i < n; i++) {
        ans=(ans+m*m%mod*((i-l)*(i-l+1)/2+(r-i)*(r-i+1)/2))%mod;
    }
    cout << (ans*inver[2]%mod*combi(n*m-2,k-2))%mod << endl;
    return 0;
}
