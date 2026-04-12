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

int n,k,m;
ll dp[125][11][1<<10];

ll solve(int n, int k, int m){
    if(k==1 && n==1){
        return 1ll;
    }else if(k==1){
        return 0ll;
    }
    REP(i,125)REP(z,11)REP(j,1<<10)dp[i][z][j] = 0;
    dp[1][0][1] = 1;
    FOR(i,1,n+1)REP(z,k+1)REP(msk,1<<k)if(dp[i][z][msk]){
        int u = __builtin_popcount(msk);
        int val = i+(i-u)-1;
        int nxt = i+(i-u);
        int zv = nxt-z;
        vi vec;
        REP(j,k)if(msk>>j&1)vec.push_back(val-j);
        reverse(ALL(vec));
        if(i<n)FOR(v,nxt,nxt+k){
            int add = v-val-1;
            if(v==nxt && z==k)continue;
            if(vec.size()+1 <= add)continue;
            bool ok = true;
            vi nv = vec;
            nv.push_back(v);
            reverse(ALL(nv));
            FOR(j,val+1,v){
                int x = nv.back(); nv.pop_back();
                if(j-x>k){
                    ok = false; break;
                }
            }
            if(!ok)continue;
            int nmsk = 0;
            for(int x : nv){
                if(v-x >= k)ok=false;
                nmsk = nmsk | (1<<(v-x));
            }
            if(!ok)continue;
            int nz = v==nxt ? (z+1) : 2;
            (dp[i+1][nz][nmsk] += dp[i][z][msk]) %= m;
            // printf("(%d,%d)[%lld] -> (%d,%d)[%lld]\n",i,msk,dp[i][msk],i+1,nmsk,dp[i+1][nmsk]);
        }
        if(i==n){
            int add = vec.size();
            int v = add + val + 1;
            bool ok = true;
            vi nv = vec;
            nv.push_back(v);
            reverse(ALL(nv));
            FOR(j,val+1,v){
                int x = nv.back(); nv.pop_back();
                if(j-x>k){
                    ok = false; break;
                }
            }
            if(ok){
                int nmsk = 0;
                for(int x : nv){
                    nmsk = nmsk | (1<<(v-x));
                }
                (dp[i+1][0][nmsk] += dp[i][z][msk]) %= m;
                // printf("(%d,%d)[%lld] -> (%d,%d)[%lld]\n",i,msk,dp[i][msk],i+1,nmsk,dp[i+1][nmsk]);
            }
        }
    }
    return dp[n+1][0][1];
}

ll naive(int n, int k, int m){
    ll ret = 0;
    vi choice(2*n,0);
    FOR(i,n,2*n)choice[i] = 1;
    do{
        int po[2][14];
        int it[2] = {0,0};
        REP(i,2*n)po[choice[i]][it[choice[i]]++] = i;
        bool ok = true;
        REP(i,n)if(abs(po[0][i]-po[1][i])>k)ok=false;
        REP(i,n-1)if(abs(po[0][i]-po[0][i+1])>k)ok=false;
        REP(i,n-1)if(abs(po[1][i]-po[1][i+1])>k)ok=false;
        REP(i,n)if(po[0][i] >= po[1][i])ok=false;
        REP(i,n-1)if(po[0][i] >= po[0][i+1])ok=false;
        REP(i,n-1)if(po[1][i] >= po[1][i+1])ok=false;
        ret += ok;
    }while(next_permutation(ALL(choice)));
    return ret;
}

int main(){
    // FOR(n,1,14)FOR(k,1,11){
    //     // puts("");
    //     ll ans1 = solve(n,k,1000000007);
    //     ll ans2 = naive(n,k,1000000007);
    //     if(ans1 != ans2){
    //         DEBUG(n);
    //         DEBUG(k);
    //         DEBUG(ans1);
    //         DEBUG(ans2);
    //         return 0;
    //     }
    // }
    cin>>n>>k>>m;
    cout << solve(n,k,m) << endl;
    return 0;
}

