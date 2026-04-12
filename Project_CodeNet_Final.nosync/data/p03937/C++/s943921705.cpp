#include <bits/stdc++.h>
#define sanyes ios_base::sync_with_stdio(0), cout.tie(0); cin.tie(0);
#define llong long long int
#define pb push_back
#define bpc __builtin_popcount
#define f first
#define s second

const llong mxn = 1e5 + 7;
const llong mod = 1e9 + 7;
const llong inf = 1e18 + 9;

using namespace std;

llong n, m, dp[1001][1001], pref[mxn], cnt = 0;
char a[1001][1001];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }if(a[1][1] != '#'){
        cout << "Impossible";
        return 0;
    }
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            if(a[i][j] == '#'){
                cnt ++;
            }
        }
    }if(cnt == n + m - 1) cout << "Possible";
    else cout << "Impossible";
    return 0;
}
