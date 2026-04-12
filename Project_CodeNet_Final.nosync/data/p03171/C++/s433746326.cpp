#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double 
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef unordered_map<int,int> mii;
typedef unordered_map<char,int> mci;
typedef unordered_map<string,int> msi;

#define pb push_back
#define f first
#define s second 
 

void solve() {
    int n; cin>>n;
    vi A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    vector<vvi> dp(n,vvi(n,vi(2))); 

    for(int i=0;i<n;i++) {
        dp[i][i][0] = A[i];
    }
    for(int i=0;i<n;i++) {
        dp[i][i][1] = -1*A[i];
    }

    for(int i=2;i<=n;i++) {
        for(int j=0;j<=n-i;j++) {
            int b = j;
            int e = j+i-1;
            dp[b][e][0] = max(A[b]+dp[b+1][e][1],A[e]+dp[b][e-1][1]);
            dp[b][e][1] = min(-A[b]+dp[b+1][e][0],-A[e]+dp[b][e-1][0]);
        }
    }
    cout<<dp[0][n-1][0]<<'\n';

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //#ifdef LOCAL
     //   freopen("input.txt", "r", stdin);
       // freopen("output.txt", "w", stdout);
    //#endif

    int tc; tc=1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}