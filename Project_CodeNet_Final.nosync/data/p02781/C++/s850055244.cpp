#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int a[n];
    rep(i,n)a[i] = s[i] - '0';
    int k;
    cin >> k;

    int dp[n][4];
    int cnt = 0;

    rep(i,n)rep(j,4)dp[i][j] = 0;

    rep(i,n){
        if(i == 0){
            dp[i][1] = a[i] - 1;
            cnt = 1;
        }else{
            dp[i][1] = dp[i-1][1] + 9;
            dp[i][2] = dp[i-1][2] + dp[i-1][1] * 9;
            dp[i][3] = dp[i-1][3] + dp[i-1][2] * 9;
            if(a[i] > 0 && cnt <= 3){
                dp[i][cnt]++;
                if(cnt <= 2){
                    dp[i][cnt+1] += a[i] - 1;
                }
                cnt++;
            }
        }
    }

    int ans = dp[n-1][k];
    if(cnt == k)ans++;

    cout << ans << endl;
    return 0;
}
 
 
