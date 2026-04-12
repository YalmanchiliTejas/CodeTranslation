#include<bits/stdc++.h>
using namespace std;
#define lc "\n"
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(0)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define int long long
#define c(a,n) for(int i = 0; i < n; i++) cin >> a[i];
#define ffor(n) for(int i = 0; i < n; i++)
 
typedef vector<int> vi;
typedef vector<float> vf;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef map<string,int> msi;
typedef map<int,int> mii;
typedef unordered_map<string,int> umsi;

 
 
int32_t main()
{
    fast_io;
    int n;
    cin>>n;
    vi a(n);
    c(a,n);
    vii dp(n+1,vi(n+1,0));
    for(int i=0;i<n;i++)
    dp[i][i]=a[i];

    for(int d=1;d<n;d++)
    {
        for(int i=0;i<n-d;i++)
        dp[i][i+d]=max(a[i]-dp[i+1][i+d],a[i+d]-dp[i][i+d-1]);
    }

    cout<<dp[0][n-1];
    return 0;
}