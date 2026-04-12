#include <bits/stdc++.h>
using namespace std;

/* macros */
#define inf 1e9
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vt vector
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())

void brute(int n, vi &nums) {
    int ans = 0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            int subans = (nums[i]%mod * nums[j]%mod)%mod;
            ans = (ans%mod + subans%mod)%mod;
        }
    }
    cout << ans << "\n";
}

void solve() {
    int n;
    cin>>n;
    vi nums(n);
    rep (i,0,n) cin>>nums[i];
    
    //brute(n,nums);
    
    int ans = 0;
    vi dp(n+1);
    dp[1] = nums[0];
    for (int i=1;i<n;i++) {
        dp[i+1] = (nums[i]%mod + dp[i]%mod)%mod;
    }
    
    for (int i=1;i<n;i++) {
        int subans = (nums[i]%mod * dp[i]%mod)%mod;
        ans += subans;
        ans %= mod;
    }
    
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}
