#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vs vector<string>
#define all(v) (v).begin(),(v).end()
#define ll long long
#define ull unsigned long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define ld long double
#define mod 1000000007
#define PI 3.141592653589793238
#define phi 1.638
#define eps 1e-7
//#define endl "\n"
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

int main() 
{
    fastio
    int n;
    cin>>n;
    vector<ll> vec(n);
    for(auto& it : vec) cin>>it;

    vector<ll> pref(n+1);
    pref[1] = vec[0];
    vector<ll> dp(n+1);
    for(int i = 3; i<=n; i+=2) 
        pref[i] = pref[i-2]+vec[i-1];

    for(int i = 2; i<=n; ++i) {
        if(i&1)
            dp[i] = max(dp[i-1], dp[i-2]+vec[i-1]);
        else {
            dp[i] = vec[i-1] + dp[i-2];
            dp[i] = max(dp[i], pref[i-1]);
        }
    }
    cout<<dp[n]<<endl;
}   
