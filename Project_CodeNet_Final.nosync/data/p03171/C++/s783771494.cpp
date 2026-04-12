#include <bits/stdc++.h>
#define MAXN 3010
#define pii pair<int, int>
#define pb push_back
typedef long long ll;

using namespace std;

ll n, a[MAXN], dp[MAXN][MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int s = 1; s <= n; s++){
        for(int i = 0; i <= n - s; i++){
            if((s + n) % 2){
                ll t = dp[i][s - 1] - a[i + s - 1];
                t = min(t, dp[i + 1][s - 1] - a[i]);
                dp[i][s] = t;

            } else{ //max
                ll t = dp[i][s - 1] + a[i + s - 1];
                t = max(t, dp[i + 1][s - 1] + a[i]);
                dp[i][s] = t;
            }
        }
    }
    cout << dp[0][n];
}