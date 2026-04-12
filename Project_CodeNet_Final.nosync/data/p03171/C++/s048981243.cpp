#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define rep(i, a) for (int i = 0; i < (a); i++)
#define repd(i, a) for (int i = (a)-1; i >= 0; i--)
#define reps(i, a, j) for (int i = (j); i < (a); i++)
#define deb(x) cout << #x << " " << x << endl;
#define debs(x) cout << #x << " " << x << " ";
#define deba(x) for (auto _i:x) cout << _i << " "; cout << endl;
#define ms(a) memset(a,0,sizeof(a));
#define mp make_pair
#define eb emplace_back
#define pii pair < int , int >
#define all(a) a.begin(),a.end() 
//int power(int x,int p){if(p==0)return 1;if(p==1)return x;if(p%2)return x*power(x,p-1);int y=power(x,p/2);return y*y;}
/*

*/

void solve() {
    int n; cin >> n;
    int arr[n]; rep(i,n) cin >> arr[i];
    int dp[n+1][n+1];
    ms(dp);
    repd(i,n) {
        rep(j,n) {
            if (i > j) continue;
            if (i == j) {
                if ((n-1)%2 == 0) dp[i][j] = arr[i]; 
            }else {
                if ( (n-(j-i+1))%2 == 0) {
                    // maximize
                    dp[i][j] = max(arr[i] + dp[i+1][j], arr[j] + dp[i][j-1]);
                }else {
                    // minimize
                    dp[i][j] = min( dp[i+1][j] , dp[i][j-1]);
                }
            }
        }
    }
    int sum = 0;
    rep(i,n) sum += arr[i];
    cout << 2*dp[0][n-1] - sum << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; t=1;
    while (t--) solve();
}



