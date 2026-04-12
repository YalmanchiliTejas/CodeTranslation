// Sky's the limit :)
#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int d, k;
vector<int> vec;
int dp[100][4][2];

int go(int pos, int cnt, bool flag) {
    if (cnt > k)
        return 0;

    if (pos == vec.size())
        return cnt == k;

    if (dp[pos][cnt][flag] != -1)
        return dp[pos][cnt][flag];

    int limit = vec[pos];
    if (flag)
        limit = 9;

    int res = 0;
    for (int i = 0; i <= limit; i++) {
        int newCnt = cnt + (i != d);
        bool newFlag = flag;
        if (flag == false && i < limit)
            newFlag = true;

        res += go(pos + 1, newCnt, newFlag);
    }

    return dp[pos][cnt][flag] = res;
}

int solve(string s) {
    vec.clear();
    for (auto c : s)
        vec.push_back(c - '0');
    
    memset(dp, -1, sizeof(dp));
    int res = go(0, 0, false);
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1; 
    // cin >> T; 
    while (T--) {
        cin >> s >> k;
        cout << solve(s) << '\n';        
    }
    
    return 0;
}

