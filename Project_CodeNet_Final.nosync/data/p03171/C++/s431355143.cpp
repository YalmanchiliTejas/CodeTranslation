#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

int MOD = 1000000007;

ll dp[3010][3010] = {0};



signed main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];

    for(ll j = 0;j < n;j++){
        for(ll i = 0;i+j < n;i++){
            ll l = i;
            ll r = i+j;
            if(j == 0){
                if((l+r)%2 == (n-1)%2){
                    dp[l][r] = a[i];
                }else{
                    dp[l][r] = -a[i];
                }
            }else if((l+r)%2 == (n-1)%2){
                dp[l][r] = max(dp[l][r-1]+a[r],dp[l+1][r]+a[l]);
            }else{
                dp[l][r] = min(dp[l][r-1]-a[r],dp[l+1][r]-a[l]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    // rep(i,n){
    //     rep(j,n){
    //         cerr << dp[i][j] << " ";
    //     }cerr << endl;
    // }

    return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://dp.contest.atcoder.jp/tasks/dp_f