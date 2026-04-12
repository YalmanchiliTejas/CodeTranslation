#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

using _loop_int = int;
#define REP(i,n) for(_loop_int i=0; i<(_loop_int)(n); i++)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a); i<(_loop_int)(b); i++)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1; i>=(_loop_int)(a); i--)

#define CHMIN(a,b) (a)=min((a),(b))
#define CHMAX(a,b) (a)=max((a),(b))
#define ALL(v) (v).begin(),(v).end()

#define DEBUG(x) cerr<<#x<<": "<<(x)<<endl
#define DEBUG_VEC(v) cerr<<#v<<": ";REP(__i,(v).size())cerr<<((v)[__i])<<", ";cerr<<endl

const ll MOD = 1000000007ll;

ll modinv(ll a){
    ll b=MOD-2, r=1;
    while(b){
        if(b&1)r=r*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return r;
}

int k,m,n;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    ll iv = modinv((ll)n*m * (n*m-1) % MOD);
    ll ans = 0;
    REP(sax,n)REP(say,m){
        if(sax==0 && say==0)continue;
        ll pr = (ll)k*(k-1)%MOD*iv%MOD;
        pr = pr * (n-sax) % MOD * (m-say) % MOD;
        pr = pr * (sax==0 || say==0 ? 1 : 2) % MOD;
        ans += pr * (sax+say) % MOD;
        ans %= MOD;
    }
    // REP(x,n)REP(y,m)REP(xx,n)REP(yy,m){
    //     if(x*m+y >= xx*m+yy)continue;
    //     ll pr = (ll)k*(k-1)%MOD*iv%MOD;
    //     ans += pr * (abs(xx-x) + abs(yy-y)) % MOD;
    //     ans %= MOD;
    // }
    ll co = 1;
    REP(i,k)co = co * (i+1) % MOD;
    co = modinv(co);
    REP(i,k)co = co * (n*m-i) % MOD;
    printf("%lld\n",ans*co%MOD);
    return 0;
}
