#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007 
#define ll long long 
#define N 3005
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define piii pair<int, pii>
#define print(x) cout << #x << "=" << x << "\t";
#define endl "\n"
#define newline cout << endl;

int n;
ll a[N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++) {
        dp[i][i] = a[i];
        a[i] += a[i - 1];
    }
    for(int len=2;len<=n;len++)
        for(int j=1;j+len-1<=n;j++)
            dp[j][j+len-1] = a[j+len-1] - a[j-1] - min(dp[j][j+len-2], dp[j+1][j+len-1]);
    cout << 2 * dp[1][n] - a[n];
    return 0;
}
