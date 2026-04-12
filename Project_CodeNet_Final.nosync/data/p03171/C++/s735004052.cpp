#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, dp[3001][3001], s[3001][3001];

signed main()
{
    
    FLASH

    cin>>n;

    fr(i, 1, n + 1){
        cin>>dp[i][i];
        s[i][i] = dp[i][i];
    }

    fr(l, 2, n + 1){
        fr(i, 1, n + 1){
            int j = i + l - 1;
            if(j > n) break;
            s[i][j] = s[i][j - 1] + dp[j][j];
            dp[i][j] = max(dp[i][i] + s[i + 1][j] - dp[i + 1][j], dp[j][j] + s[i][j - 1] - dp[i][j - 1]);
        }
    }

    cout<<2*dp[1][n] - s[1][n]<<'\n';
}