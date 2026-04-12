#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int mpow(int a,int b){
    int ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}

int N;
int H[111];

int dp[111][111],dp2[111][111];

void solve(int l,int r,int b){
    int &ret=dp[l][r];
    int &ret2=dp2[l][r];

    if(ret!=-1)return;

    int bb=*min_element(H+l,H+r);
    if(*max_element(H+l,H+r)==bb){
        ret=(mpow(2,r-l)-2+mod)%mod;
        ret2=mpow(2,bb-b);
        return;
    }

    vpint lis;
    int cur=l;
    while(cur<r){
        if(H[cur]==bb){
            cur++;
            continue;
        }
        int nex=cur;
        while(nex<r&&H[nex]>bb)nex++;
        lis.pb({cur,nex});
        solve(cur,nex,bb);
        cur=nex;
    }

    int num=count(H+l,H+r,bb);

    int x=mpow(2,num);
    ret2=2;
    for(auto &p:lis){
        x=x*(dp[p.fi][p.se]+dp2[p.fi][p.se]*2)%mod;
        ret2=ret2*dp2[p.fi][p.se]%mod;
    }
    ret=(x-ret2+mod)%mod;
    ret2=ret2*mpow(2,bb-b-1)%mod;
}

signed main(){
    cin>>N;
    rep(i,N)cin>>H[i];

    memset(dp,-1,sizeof(dp));
    solve(0,N,0);
    cout<<(dp[0][N]+dp2[0][N])%mod<<endl;
    return 0;
}
