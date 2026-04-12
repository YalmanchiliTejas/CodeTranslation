#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int         ll
typedef vector<int> vi;
#define test        int t; cin >> t; while(t--)
#define max(a,b)   (a>b?a:b)
#define min(a,b)   (a<b?a:b)
const int mod = 1000000007;

int n;
vector<int> v;


int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;
    vector<int> dp(n + 1);
    v = vector<int>(n + 1);
    vector<int> pre(n + 1);
    // dp[0]=INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        if (i % 2) {
            pre[i] = v[i];
            if (i > 1)
                pre[i] += pre[i - 2];
        }

    }

    for (int i = 2; i <= n; ++i){
            if(i%2){
                dp[i]=max(dp[i-1],dp[i-2]+v[i]);
            }else{
                dp[i]=max(pre[i-1],dp[i-2]+v[i]);
            }
    }
    // for(auto it:dp) cout<<it<<" ";
    // cout<<endl;
    cout<<dp[n];
    return 0;
}