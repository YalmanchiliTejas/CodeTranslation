#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
// const ll MOD = 1000000007;
const ll inf = 999999999999;

int main() {
    int n; cin >> n;
    vector<ll> a(n+2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<pair<int,int>,ll> dp;
    map<pair<int,int>,int> mp;
    dp[make_pair(1, 0)] = 0;
    mp[make_pair(1, 0)] = 0;
    dp[make_pair(1, 1)] = a[1];
    mp[make_pair(1, 1)] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = (i - 1) / 2; j <= (i + 1) / 2; j++) {
            if (dp.find(make_pair(i-1,j)) != dp.end()) {
                if(dp.find(make_pair(i,j)) == dp.end()) dp[make_pair(i,j)] = dp[make_pair(i-1,j)];
                else dp[make_pair(i,j)] = max(dp[make_pair(i,j)],dp[make_pair(i-1,j)]);
            }
            if (dp.find(make_pair(i-1,j-1)) != dp.end()) {
                if(dp.find(make_pair(i,j-1)) == dp.end()) dp[make_pair(i,j-1)] = dp[make_pair(i-1,j-1)];
                else dp[make_pair(i,j-1)] = max(dp[make_pair(i,j-1)],dp[make_pair(i-1,j-1)]); 
                if (mp[make_pair(i-1,j-1)] < i -1) {
                    if (dp.find(make_pair(i,j)) == dp.end()) dp[make_pair(i,j)] = dp[make_pair(i-1,j-1)] + a[i];
                    else dp[make_pair(i,j)] = max(dp[make_pair(i,j)], dp[make_pair(i-1,j-1)] + a[i]);
                    if(dp[make_pair(i,j)] == dp[make_pair(i-1,j-1)] + a[i]) mp[make_pair(i,j)] = i; 
                }
            }
            if (dp.find(make_pair(i-2,j-1)) != dp.end()) {
                if (dp.find(make_pair(i,j)) == dp.end()) dp[make_pair(i,j)] = dp[make_pair(i-2,j-1)] + a[i];
                else dp[make_pair(i,j)] = max(dp[make_pair(i,j)], dp[make_pair(i-2,j-1)] + a[i]);
                if(dp[make_pair(i,j)] == dp[make_pair(i-2,j-1)] + a[i]) mp[make_pair(i,j)] = i;
            }
        }
    }
    cout << dp[make_pair(n, n / 2)] << "\n";
}