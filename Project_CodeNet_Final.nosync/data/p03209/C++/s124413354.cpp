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

ll sums[50];
ll patties[50];

ll lv1[5] = {0, 1, 2, 3, 3};
ll lv0[1] = {1};

ll dfs(ll N, ll X) {
    if (X <= 0) return 0;
    if (N==0) {
        return lv0[X-1];
    }
    if (N==1) {
        return lv1[X-1];
    }
    if (sums[N-1] - 1 <= X) {
        return patties[N-1];
    }

    ll ret = 0;
    ll mid_ind = sums[N-1] / 2 + 1;
    if (X < mid_ind - 1) {
        ret = dfs(N-1, X-1);
    }
    if (X == mid_ind - 1) {
        ret = patties[N-2];
    }
    if (X == mid_ind) {
        ret = 1 + patties[N-2];
    }
    if (X  == mid_ind + 1) {
        ret = 1 + patties[N-2];
    }
    if (mid_ind + 1 < X) {
        ret = patties[N-2] + 1 + dfs(N-1, X-mid_ind);
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    ll N;
    ll X;
    cin >> N >> X;

    ll sum = 1;
    ll patty = 1;
    
    REP(i, 50) {
        sum = 1 + sum + 1 + sum + 1;
        sums[i] = sum;
        patty = patty + 1 + patty;
        patties[i] = patty;
    }
    cout << dfs(N, X) << endl;
    
    return 0;
}
