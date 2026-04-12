#include <bits/stdc++.h>
#define vi vector<int>
#define rep(i, xtz, n) for(int i=xtz; i<n; i++)
#define repx(i, xtz, n) for(int i=xtz; i>=n; i--)
#define lli long long int

using namespace std;

lli dp[3005][3005];

int main(){
    //freopen("i.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<lli> vec(n);
    rep(i, 0, n) scanf("%d", &vec[i]);
    repx(L, n-1, 0){
        rep(R, L, n){
            if(L==R) dp[L][R] = vec[L]; 
            else{
                dp[L][R] = max(vec[L]-dp[L+1][R], vec[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1];
}