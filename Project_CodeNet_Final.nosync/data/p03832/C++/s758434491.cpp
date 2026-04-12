#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

ll modpow(ll a,ll b){
    ll ret=1;
    while(b>0){
        if(b&1)(ret*=a)%=MOD;
        (a*=a)%=MOD;
        b>>=1;
    }
    return ret;
}

vector<ll> kaijo;
vector<ll> gyaku;
void prepair(ll n){
    kaijo.PB(1);
    FOR(i,1,n+1){
        kaijo.PB((kaijo[i-1]*i)%MOD);
    }
    FOR(i,0,n+1){
        gyaku.PB(modpow(kaijo[i],MOD-2));
    }
}

//AtCoder Regular Contest 067 - Grouping
int main(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    ll C[1001][1001]={};
    C[0][0]=1;
    FOR(i,1,n+1){
        FOR(j,0,i+1){
            if(j==0) C[i][j]=1;
            else C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
    }
    prepair(n+1);
    //dp[x][y]:x人以下のグループで全体y人のやつ
    //dp[x][y]=Sum(dp[x-1][y-kx])(k=0,c,c+1,...,min(d,y/x))
    ll dp[1001][1001]={};
    FOR(i,0,1001) dp[i][0]=1;
    FOR(x,a,b+1) FOR(y,0,n+1){
        dp[x][y]=dp[x-1][y];
        ll C2[1001]={}; C2[0]=1;
        FOR(j,1,min(d,y/x)+1){
            (C2[j]=C2[j-1]*C[n-y+j*x][x])%=MOD;
        }
        FOR(j,c,min(d,y/x)+1){
            (C2[j]*=gyaku[j])%=MOD;
            ll kari=(dp[x-1][y-j*x]*C2[j])%MOD;
            (dp[x][y]+=kari)%=MOD;
        }
    }
    /**
    FOR(i,0,10){
        FOR(j,0,10){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    **/
    co(dp[b][n]);
}
