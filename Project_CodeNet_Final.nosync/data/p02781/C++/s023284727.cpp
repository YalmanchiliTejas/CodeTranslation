#include<bits/stdc++.h>
using namespace std;
string s;
int k,n;
int dp[120][5][2];

int fun(int pos, int cnt, int f) {
    if (cnt > k) return 0;
    if (pos == n) {
        if (cnt == k) return 1;
        return 0;
    }
    if(dp[pos][cnt][f] != -1) return dp[pos][cnt][f];

    int res = 0, limit;
    int now = s[pos] - '0';
    if (f) limit = 9;
    else limit = now;

    for (int i = 0; i <= limit; i++) {
        int ncnt = cnt, nf = f;
        if (!f && i < now) nf = 1;
        if (i != 0) ncnt++;
        if (ncnt <= k) res += fun(pos + 1, ncnt, nf);
    }

    return dp[pos][cnt][f] = res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> s >> k;
    n = s.size();
//    k = n - k;

    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, 0) << '\n';
}
