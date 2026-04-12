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
#define REP(i,n) for(int i=0;i<n;++i)
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
    string sn;
    cin >> sn;
    int k;
    cin >> k;
    //ll ans = 0;
    int l = (int)sn.size();
    vvll dp(l,vll(8,0LL));
    dp[0][1] = 1;
    dp[0][5] = (ll)(sn[0]-'0')-1;
    for(ll i = 1;i<l;++i){
        ll num = (ll)(sn[i]-'0');
        if(num==0){
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }else{
            dp[i][1] = 0;
            dp[i][2] = dp[i-1][1];
            dp[i][3] = dp[i-1][2];
        }
        if(num==0){
            dp[i][5] = dp[i-1][5]+9;
            dp[i][6] = dp[i-1][6]+9*dp[i-1][5];
            dp[i][7] = dp[i-1][7]+9*dp[i-1][6];
        }else{
            dp[i][5] = dp[i-1][1] + dp[i-1][5] + 9LL;
            dp[i][6] = dp[i-1][2] + dp[i-1][1]*(num-1)+ dp[i-1][5]*9 + dp[i-1][6];
            dp[i][7] = dp[i-1][3] + dp[i-1][2]*(num-1)+ dp[i-1][6]*9 + dp[i-1][7];
        }
    }
    /*
    REP(i,l){
        cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][5] << " " << dp[i][6] << endl;
    }
    */
    cout << dp[l-1][k] + dp[l-1][k+4] << endl;
    return 0;
}