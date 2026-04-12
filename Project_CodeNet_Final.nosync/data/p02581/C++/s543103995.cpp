#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;
void chmax(int& a, int b) { a = max(a, b);}
void chmin(int& a,int b) {a = min(a,b);}

int main(){
    int n;cin >> n;
    vector<vector<int>> dp(2005,vector<int>(2005,-INF));
    vector<int> a(3*n);rep(i,3*n) cin >> a[i],--a[i];

    int m = n+1;
    auto upd = [&](int i,int j,int x){
        chmax(dp[i][j],x);
        chmax(dp[j][i],x);
        chmax(dp[j][n],x);
        chmax(dp[n][j],x);
        chmax(dp[i][n],x);
        chmax(dp[n][i],x);
        chmax(dp[n][n],x);
    };

    upd(a[0],a[1],0);
    int base = 0;
    for(int ai = 2;ai < 3*n-1;ai += 3){
        int x = a[ai],y = a[ai+1],z = a[ai+2];
        if(x == y && y == z) {
            base++;
            continue;
        }
        vector<tuple<int,int,int>> q;
        rep(ri,3){
            {
                rep(b,m){
                    int now = dp[b][n];
                    if(y == z) chmax(now,dp[b][y]+1);
                    q.emplace_back(b,x,now);
                }
            }
            {
                int now = max(dp[n][n],dp[z][z]+1);
                q.emplace_back(x,y,now); 
            }
            swap(x,y);swap(y,z);
        }
        for(auto t:q){
            int i,j,k;
            tie(i,j,k) = t;
            upd(i,j,k);
        }
    }
    int ans = dp[n][n];
    int l = a[3*n-1];
    chmax(ans,dp[l][l]+1);
    cout << ans+base << endl;   
}