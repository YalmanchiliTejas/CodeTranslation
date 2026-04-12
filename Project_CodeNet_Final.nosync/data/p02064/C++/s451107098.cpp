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

int n,s,t;

int query(int x, int y){
    printf("? %d %d\n",x,y); fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int main(){
    scanf("%d%d%d",&n,&s,&t);
    assert(n>=2);
    if(n==2){
        printf("! %d %d\n",s,t); fflush(stdout);
        return 0;
    }
    int len = query(s,t);
    set<pii> po;
    po.insert(pii(0,s));
    po.insert(pii(len,t));
    set<int> dists;
    dists.insert(0);
    dists.insert(len);
    FOR(v,1,n+1){
        if(v==s || v==t)continue;
        int p = query(s,v);
        int q = query(v,t);
        if(p+q != len)continue;
        if(dists.count(p))continue;
        auto it = po.lower_bound(pii(p,-1));
        pii T = *it;
        it--;
        pii S = *it;
        int x = query(S.second, v);
        int y = query(v, T.second);
        if(x+y != T.first-S.first)continue;
        dists.insert(p);
        po.insert(pii(p,v));
    }
    // out
    printf("!");
    for(pii P : po)printf(" %d",P.second);
    puts("");
    fflush(stdout);
    return 0;
}

