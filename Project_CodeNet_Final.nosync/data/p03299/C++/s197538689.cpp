#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 105;

int h[maxn];
int a[maxn], tot;
int id[maxn];
const int mod = 1e9 + 7;

void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int dp[maxn][maxn];

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

int power2(int l, int r){
    int ret = (qpow(2, r + 1) - qpow(2, l) + mod) % mod;
    return ret;
}

int solve(vector<int> heights){
    if(heights.size() == 0){
        return 1;
    }
    memset(dp, 0, sizeof(dp));
    int h1 = a[heights[0]];
    dp[1][0] = 2;
    dp[1][1] = power2(h1 - a[1] + 1, h1 - 1);
    for(int i = 2;i <= heights[0];i++){
        dp[1][i] = power2(h1 - a[i] + 1, h1 - a[i - 1]);
    }
    int sz = heights.size();
    for(int i = 1;i < sz;i++){
        for(int j = 1;j <= heights[i - 1];j++){
            if(heights[i] >= j){
                int sum = max(0, a[heights[i]] - a[heights[i - 1]]);
                sum = qpow(2, sum);
                add(dp[i + 1][j], 1LL * dp[i][j] * sum % mod);
            }else{
                add(dp[i + 1][0], dp[i][j] * 2 % mod); 
            }
        }
        if(heights[i] <= heights[i - 1]){
            add(dp[i + 1][0], dp[i][0] * 2 % mod);
        }else{
            h1 = a[heights[i]];
            for(int j = heights[i - 1] + 1;j <= heights[i];j++){
                int sum = power2(h1 - a[j] + 1, h1 - a[j - 1]);
                add(dp[i + 1][j], 1LL * dp[i][0] * sum % mod);
            }
            add(dp[i + 1][0], dp[i][0] * 2 % mod);
        }
    }
    //for(int i = 1;i <= sz;i++){
    //    for(int j = 0;j <= heights[i - 1];j++){
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    int ans = 0;
    for(int j = 0;j <= heights[sz - 1];j++){
        add(ans, dp[sz][j]);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    tot = 0;
    for(int i = 1;i <= n;i++){
        cin >> h[i];
        if(h[i] > 1)
            a[++tot] = h[i];
    }
    sort(a + 1, a + 1 + tot);
    tot = unique(a + 1, a + 1 + tot) - a - 1;
    for(int i = 1;i <= n;i++){
        if(h[i] == 1)
            continue;
        id[i] = lower_bound(a + 1, a + 1 + tot, h[i]) - a;
    }
    vector<int> his;
    int ans = 1;
    for(int i = 1;i <= n;i++){
        if(h[i] == 1){
            ans = ans * 2 % mod;
            ans = 1LL * ans * solve(his) % mod;
            his.clear();
        }else{
            his.push_back(id[i]);
        }
    }
    if(!his.empty()){
        ans = 1LL * ans * solve(his) % mod;
    }
    cout << ans << endl;
    return 0;
}
