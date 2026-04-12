#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <deque>
#define rep(i,N) for (int i = 0;i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll INF = 1e18;
int N;
vector<vector<ll>> dp;
vector<ll> a(N);

ll rec(int l = 0,int r = N){
    if(l==r) return 0;
    ll &ret = dp[l][r];
    if(ret != INF) return ret;
    if((N - (r-l) )% 2==0){ //%の計算順序は意外と早い
        ret = max(a[l]+rec(l+1,r),a[r-1]+rec(l,r-1));
    }else{
        ret = min(rec(l+1,r)-a[l],rec(l,r-1)-a[r-1]);
    }

    return ret;
}

int main(){
    cin >> N;
    a.assign(N, 0);//grobal scope の　vectorはすべてこれで初期化しよう
    rep(i,N) cin >> a[i];
    dp.assign(N+1,vector<ll>(N+1,INF));

    ll ans = rec(0,N);

    cout << ans << endl;

    
}