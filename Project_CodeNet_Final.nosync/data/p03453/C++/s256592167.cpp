#include<bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e5 + 5;

vector < pp > V[N];
vector < int > U[N],Y[N];
priority_queue < pair < int , pp > > Q;

int D[N],M[N],MM[N],T[N],t,n,m,i,j,a,b,x,y,z,u,ans,zz;

int f(int x){
    return x*x % mod;
}

signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
    for(; m-- ;){
        scanf("%lld%lld%lld",&x,&y,&z);
        V[x].pb(mp(y,z));
        V[y].pb(mp(x,z));
    }
    
    Q.push(mp(-1,mp(a,0)));
    for(; Q.size() ;){
        x = Q.top().nd.st;
        y = Q.top().nd.nd;
        u = Q.top().st;
        Q.pop();
        if(D[x] == -u || !D[x]) { U[y].pb(x); Y[x].pb(y); }
        if(D[x]) continue;
        T[++t] = x;
        D[x] = -u;
        for(i=0;i<V[x].size();i++)
            Q.push(mp(u-V[x][i].nd,mp(V[x][i].st,x)));
    }

    for(i=1;i<=n;i++) D[i]--;

    zz = D[b];
    M[b] = 1;
    for(i=t; i ; i--){
        x = T[i];
        for(j=0;j<U[x].size();j++)
            M[x] = (M[x] + M[ U[x][j] ]) % mod;
    }
    
    ans = f(M[a]);
    MM[a] = 1;
    for(i=1;i<=t;i++){
        x = T[i];
        for(j=0;j<Y[x].size();j++)
            MM[x] = (MM[x] + MM[ Y[x][j] ]) % mod;

        if(D[x]*2 == zz) ans = (ans - f(M[x]*MM[x]%mod)) % mod;
        for(j=0;j<U[x].size();j++)
            if(D[x]*2 < zz && D[ U[x][j] ]*2 > zz)
                ans = (ans - f(MM[x]*M[ U[x][j] ]%mod)) % mod;
    }
    
    cout << (ans + mod) % mod;
    return 0;
}