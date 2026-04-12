#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(ll i=0; i<(ll)(n); i++)
#define FOR(i,n,m) for (ll i=n; i<(ll)(m); i++)
#define pb push_back
#define INF 1000000007LL
#define all(a) (a).begin(),(a).end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

typedef long long ll;
typedef pair<int,int> p;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

ll N, K;
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    
    // bを固定
    ll ans = 0;
    FOR(b, K+1, N+1) {
        ll n = N / b;
        if (N % b >= K) {
            ans += (N % b) - K + 1;
            ans += n * (b-1-K+1);
        } else {
            ans += n * (b-1-K+1);
        }
    }
    if (K == 0) ans -= N;
    cout << ans << endl;
    return 0;
}
