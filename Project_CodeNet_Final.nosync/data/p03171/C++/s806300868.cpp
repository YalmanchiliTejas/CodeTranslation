#include<bits/stdc++.h>

using namespace std;

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)

int findOptimalValue(int i, int j, bool chance, vector< vector<pii> > &dp, vector<int> &A)
{
    if(i>j || i >= A.size() || j < 0)
        return 0;
    if(chance)
    {
        if(dp[i][j].x == -1)
            dp[i][j].x = max(A[i] + findOptimalValue(i+1, j, 0, dp, A), A[j] + findOptimalValue(i, j-1, 0, dp, A));
        return dp[i][j].x;
    }
    else
    {
        if(dp[i][j].y == -1)
            dp[i][j].y = min(findOptimalValue(i+1, j, 1, dp, A) - A[i], findOptimalValue(i, j-1, 1, dp, A) - A[j]);
        return dp[i][j].y;
    }
}

void solve()
{
    int n, i, j;
    cin>>n;
    vector<int> A(n);
    for(i = 0; i < n; i++)
        cin>>A[i];
    vector< vector<pii> > dp(n, vector<pii> (n, make_pair(-1,-1)));
    i = 0; j = n-1;
    // for X-Y we select X when boolean is 1
    cout<<findOptimalValue(i, j, 1, dp, A)<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
	tc = 1;
    // cin>>tc;
    while(tc--)
        solve();
    return 0;
}
