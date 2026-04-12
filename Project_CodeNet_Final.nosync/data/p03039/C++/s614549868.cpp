#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define all(ppp) ppp.begin(),ppp.end()
#define out(ppp) cout<<(ppp)<<endl
#define out1(ppp) cout<<(ppp) 
#define MAX_CHAR 256

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define pb push_back

typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vpi> vvpi;

typedef set<pi> spi;

const int INF=INT_MAX;
int N,M,K;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];

ll mymod(ll a,ll b){
    a%=MOD;
    ll result=1;
    while(b>0){
        if(b&1){
            result=(result*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return result;
    
}
ll modInverse(ll n){
    return mymod(n,MOD-2);
}

void init_combination(){
    const int MAX = 10000002;   //1e6+2
    Factorial[0]=1;
    inv[0]=1;
    for(int i=1;i<=MAX;i++){
        Factorial[i]=(Factorial[i-1]*i)%MOD;
    }
    FactorialInv[MAX]=modInverse(Factorial[MAX]);
    for(int i=MAX-1;i>=0;i--){
        FactorialInv[i]=FactorialInv[i+1]*(i+1)%MOD;
    }
    for(int i=1;i<=MAX;i++){
        inv[i]=(FactorialInv[i]*FactorialInv[i-1])%MOD;
    }
}

ll combination(ll n,ll k){
    if(n==k||k==0){
        return 1;
    }
    if(n<k){
        return 0;
    }
    ll ans=(Factorial[n]*FactorialInv[k])%MOD;
    ans=(ans*FactorialInv[n-k])%MOD;
    return ans;
}
void solve(){
    cin>>N>>M>>K;
    init_combination();
    ll ans=combination(N*M-2,K-2);
    ll sum=0;
    for(ll i=1;i<M;i++){
        ll now=M-i;
        now=(now*N*N)%MOD;
        now=now*i%MOD;
        sum=(sum+now)%MOD;
    }
    for(int i=1;i<N;i++){
        ll now=N-i;
        now=(now*M*M)%MOD;
        now=(now*i)%MOD;
        sum=(sum+now)%MOD;
    }
    sum=(sum*ans)%MOD;
    out(sum);


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}