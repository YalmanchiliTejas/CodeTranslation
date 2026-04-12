#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = 1000000007;
int sum(int a, int b){
    if (a+b<0) return a+b+mod;
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int mult(int a, int b){
    return ((ll) a * (ll) b) % (ll) mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    if (s[0] == 'B'){
        for (int i=0; i < s.size(); i++){
            if (s[i] == 'B') s[i] = 'R';
            else s[i] = 'B';
        }
    }
    int index = -1;
    for (int i=0; i < m; i++) if (s[i] == 'B'){
        index = i;
        break;
    }
    if (index == -1){
        int dp[n][2][2];
        for (int i=0; i < n; i++) for (int j=0; j < 2; j++) for (int k=0; k < 2; k++) dp[i][j][k] = 0;
        dp[0][0][0] = 1, dp[0][1][1] = 1;
        for (int i=1; i < n; i++){
            for (int j=0; j < 2; j++) for (int k=0; k < 2; k++) for (int e=0; e < 2; e++){
                if (j==0 && e==0) continue;
                dp[i][e][k] = sum(dp[i][e][k], dp[i-1][j][k]);
            }
        }
        int ans = 0;
        for (int i=0;i<2;i++) for (int j=0;j<2;j++) if (i!=0 || j != 0) ans=sum(ans, dp[n-1][i][j]);
        cout << ans;
        return 0;
    }
    if (n%2 != 0){
        cout << 0;
        return 0;
    }
    int mx = n+1;
    if (index % 2 == 0) mx = min(mx, index+1);
    else mx = min(mx, index);
    int cnt = 0;
    for (int i=index+1; i < m; i++){
        if (s[i] == 'R') cnt++;
        else{
            if (cnt % 2 != 0) mx = min(mx, cnt);
            cnt = 0;
        }
    }
    int M = (mx+1)/2;
    //cout << mx << endl;
    int dp[n/2+1];
    dp[0] = 1;
    int ans = 0;
    int pref[n/2+2];
    pref[0] = 0;
    pref[1] = 1;
    for (int i=1; i <= n/2; i++){
        if (i < n/2){
            int brd = max((int) 0, i-M);
            dp[i] = sum(pref[i], -pref[brd]);
            pref[i+1] = sum(pref[i], dp[i]);
        }
        else{
            int brd = max((int) 0, i-M);
            for (int j=i-1; j >= brd; j--){
                int val = dp[j];
                int len = 2*(i-j)-1;
                int shift = len+1;
                ans = sum(ans, mult(shift, val));
            }
        }
    }
    cout << ans;
}
