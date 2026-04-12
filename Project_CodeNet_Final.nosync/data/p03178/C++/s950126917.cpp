#include <bits/stdc++.h>
using namespace std;
#define int long long int
// #include "../../Template.cpp"

const int mod = (1e9) + 7;

vector<int> arr;
int n, d;
vector<vector<int>> dp;

int solve(int ind, int curr = 0, bool small = 0) {
    if(ind == n) {
        return curr == 0;
    }
    if(small == 1 && dp[ind][curr] != -1) {
        return dp[ind][curr];
    }
    int ans = 0;
    int limit = small ? 9 : arr[ind];
    for(int i = 0; i <= limit; i ++) {
        if(i!= limit)
            ans += (solve(ind+1, (curr+i)%d, 1));
        else 
            ans += (solve(ind+1, (curr+i)%d, small));
        ans %= mod;
    }
    if(small == 1)
        dp[ind][curr] = ans;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s >> d;
    n = s.size();
    for(auto i : s) {
        arr.push_back(i - '0');
    }
    dp.resize(n+1, vector<int>(d, -1));
    int ans = solve(0, 0);
    ans = (ans - 1 + mod) % mod;
    cout << ans << endl;
    return 0;
}