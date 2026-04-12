//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(ll i=0;i<n;++i)
#define mod (ll)(1e9+7)
#define FIX(a) ((a)%mod+mod)%mod
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define fi first
#define se second
#define pb push_back
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vll a(n);
    REP(i,n) cin >> a[i];
    vvll dp(n+1,vll(3,0));
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[1][2] = a[0];
    for(int i=1;i<n;++i){
        if((i+1)%2==0){
            dp[i+1][0] = max(dp[i][1], dp[i-1][0]+a[i]);
            dp[i+1][2] = max(dp[i-1][2]+a[i], dp[i][2]);
            dp[i+1][1] = dp[i+1][2];

        }else{
            dp[i+1][1] = max(dp[i][2], dp[i-1][1]+a[i]);
            dp[i+1][0] = dp[i+1][1];
            dp[i+1][2] = dp[i-1][2]+a[i];
        }
    }
    cout << dp[n][1] << endl;
    return 0;
}