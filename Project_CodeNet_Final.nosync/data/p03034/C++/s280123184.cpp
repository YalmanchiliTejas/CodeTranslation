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

int n;
int s[125252];

int main(){
    scanf("%d",&n);
    REP(i,n)scanf("%d",s+i);
    ll ans = 0;
    FOR(d,1,n/2){
        int t = 0;
        ll tmp = 0;
        int l = 0, r = n-1;
        while(true){
            t++;
            l += d;
            if(l==r || l>=n)break;
            r -= d;
            if(l==r || r<0)break;
            int a = n-1-t*d;
            int b = a-d;
            if(a<=0 || b<=0)break;
            tmp += s[l];
            tmp += s[r];
            CHMAX(ans, tmp);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
