                       //  @ /\/\ BESH //

#include <bits/stdc++.h>
#define inp_out_work ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testCase    int T; cin>>T; while(T--)
#define fr(i,n) for(int i=0;i<n;i++)
#define fro(i,s,e) for(int i=s;i<=e;i++)
#define endl '\n'
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define pb push_back


using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100001;
const int mod = 1000000007;

int main(){
    int n;
    cin>>n;
    int a[n];
    fr(i,n)cin>>a[i];

    ll dp[n][n];

    fr(i,n)dp[i][i] = (n&1)? a[i] : 0;
    fr(i,n-1)dp[i][i+1] = (n&1)?  min(a[i] , a[i+1]) : max(a[i], a[i+1]);

    for(int len = 3; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            if((len&1) == (n&1))dp[i][j] = max(a[i] + dp[i+1][j], a[j] + dp[i][j-1]);
            else dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
        }
    }

    ll ans = dp[0][n-1];

    ans = 2*ans - accumulate(a, a+n, 0LL);

    cout<< ans << endl;

}
