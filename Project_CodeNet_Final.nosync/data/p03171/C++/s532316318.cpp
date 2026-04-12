#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
}

ll dp[4000][4000];
ll arr[4000];
ll n;

ll solve(ll low, ll high){
    if(high-low<=1) return max(arr[low],arr[high]);
    
    if(dp[low][high]!=-1) return dp[low][high];
    
    ll ans1 = solve(low+1, high-1);
    ll ans2 = solve(low+2, high);
    ll ans3 = solve(low, high-2);
    
    ll case1 = min(ans1, ans2)+arr[low];
    ll case2 = min(ans1, ans3)+arr[high];
    
    return dp[low][high] = max(case1, case2);
}

int main() {
    fast();
    memset(dp,-1,sizeof(dp));
    cin >>n;
    ll sum=0;
    for(ll i=0;i<n;i++){
        cin >>arr[i];
        sum += arr[i];
    }
    
    cout<<2*solve(0,n-1)-sum;
    
    return 0;
}
