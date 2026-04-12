#include "bits/stdc++.h"

#define REP(i, n, N) for(ll i=(n); i<(N); i++)
#define RREP(i, n, N) for(ll i=(N-1); i>=n; i--)
#define CK(n, a, b) ((a)<=(n)&&(n)<(b))
#define ALL(v) (v).begin(),(v).end()
#define MCP(a, b) memcpy(b,a,sizeof(b))
#define p(s) cout<<(s)<<endl
#define p2(a, b) cout<<(a)<<" "<<(b)<<endl
#define v2(T) vector<vector<T>>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

ll N, X;
ll P[55];
ll sum[55];
ll ans;
ll dfs(ll a, ll x){

    ll ret = 0;
    if(x<=a){
        return 0;
    }else if(x==1) ret=1;
    else{
        if(x==sum[a]){
            ret+=P[a];
        }
        else if(x==sum[a]/2+1){
            ret += 1 + P[a-1];
        }
        else if(x < sum[a]/2+1){
            ret += dfs(a-1, x-1);
        }else if(x > sum[a]/2){
            ret += dfs(a-1, x-P[a]) + P[a-1] + 1;
        }
    }
    return ret;
}
int main() {
    cin >> N >> X;
    P[0] = 1;
    sum[0]=1;
    REP(i,1,N+1){
        P[i] = 2*P[i-1]+1;
        sum[i] = 2*sum[i-1]+3;
    }
    ans += dfs(N, X);
    p(ans);
    return 0;
}
