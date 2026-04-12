/*
Author: Racer5x
 ***************************************   UNAUTHORISED COPYING OF CODE PROHIBITED   **********************************
*/
 
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
#define int         long long
#define double      long double
#define pb          emplace_back
#define pf          emplace_front
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define x           first
#define y           second
#define endl        '\n'
#define hell        998244353 
#define PI          3.141592653589
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MAX         2000000000000000000
#define M           1000000007
using namespace std;
 
signed main()
{
    tezz
    
    string s;
    cin>>s;
    int d;
    cin>>d;
    int n = s.length();
    vector<vi> dp(d, vector<int> (2));
    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        vector<vi> new_dp(d, vector<int>(2));

        for(int sum = 0; sum<d; sum++){
            for(int did = 0; did<2; did++){ // it signifies whether or not we have taken a smaller value before
                for(int digits = 0; digits<10; digits++){
                    if(!did && digits > (s[i] - '0')) break;

                    int arg1 = (sum + digits) % d, arg2 = (did || (digits < s[i] - '0'));

                    new_dp[arg1][arg2] = (new_dp[arg1][arg2] + dp[sum][did]) % M; 
                }
            }
        }
        dp = new_dp;
    }

    int ans = (dp[0][0] + dp[0][1]) % M;
    ans = (ans - 1 + M) % M;

    cout<<ans;
} 