#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

ll nums[100];

ll dfs(ll n, ll x){
    if(n == 0 && x == 1) return 1;
    ll res;
    if(x == 0) res = 0;
    else if(x == 1) res = 0;
    else if(x <= nums[n-1] + 1) res = dfs(n-1, x-1);
    else if(x == nums[n-1] + 1) res = dfs(n-1, nums[n-1]) + 1;
    else if(x <= 2 + 2 * nums[n-1]) res = dfs(n-1, nums[n-1]) + dfs(n-1, x - (2 + nums[n-1])) + 1;
    else if(x == nums[n]) res = 2 * dfs(n-1, nums[n-1]) + 1;
    return res;
}

int main(){
    ll n, x;
    cin >> n >> x;
    nums[0] = 1;
    rep(i, 0, n) nums[i+1] = 2*nums[i] + 3;
    cout << dfs(n, x) << endl;
    return 0;
}