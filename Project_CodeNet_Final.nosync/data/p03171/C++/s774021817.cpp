#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define REV(i,a,n) for(int i=a;i>=n;i--)
#define all(a) a.begin(),a.end()
#define UB upper_bound
#define LB lower_bound
const int NUM = 2e5 + 5;
int dp[3001][3001][2];

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int num_tests=1; 
    //cin >> num_tests;
    while(num_tests-->0){
        int n; cin >> n;
        vector<int> a(n);
        for(auto &x:a) cin >> x;
        FOR(i,0,n)
            dp[i][i][0] = a[i], dp[i][i][1] = 0;
        for(int R_L = 1; R_L < n; R_L++){
            for(int L = 0; L + R_L < n; L++){
                int R = L + R_L;
                dp[L][R][0] = max(a[L] + dp[L+1][R][1],a[R] + dp[L][R-1][1]);
                dp[L][R][1] = min(dp[L+1][R][0],dp[L][R-1][0]);
            }
        }
        int sm = 0;
        for(auto x:a)
            sm += x;
        cout << 2*dp[0][n-1][0] - sm;
    }   
}