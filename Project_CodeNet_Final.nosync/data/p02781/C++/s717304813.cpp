#include <iostream>
#include <cstring>
using namespace std;

string s;
int k, up[105], n;
long long dp[105][2][4];

long long dfs(int pos, int lim, int cnt){
    if (pos == -1 && cnt == k) return 1;
    else if (pos == -1) return 0;
    if (cnt > k) return 0;
    if (dp[pos][lim][cnt] != -1) return dp[pos][lim][cnt];
    int upper;
    long long ret = 0;
    if (lim == 1) upper = up[pos];
    else upper = 9;
    for (int i = 0; i <= upper; i++){
        ret += dfs(pos-1, lim&&i==upper, cnt+(i!=0));
    }
    return dp[pos][lim][cnt] = ret;
}

long long solve(){
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++){
        up[i] = s[n-1-i]-'0';
    }
    return dfs(n-1, 1, 0);
}

int main() {
    cin >> s;
    cin >> k;
    n = s.length();
    cout << solve() << "\n";
}
