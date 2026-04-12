#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


using namespace std;

#define int         long long
#define ld          double
#define vi          vector <int>
#define vp          vector <pair<int,int>>
#define vvi         vector <vector <int>>
#define pb          push_back
#define mp          make_pair
#define pi          pair<int,int>
#define all(a)      a.begin(),a.end()
#define sz(a)       a.size()
#define sl(a)       a.length()
#define rev(a)      sort(all(a),greater<int>())
#define ff          first
#define ss          second
#define minel(a)	*min_element(all(a))
#define maxel(a)	*max_element(all(a))
#define Mod         1000000007
#define deb(x)      cout << x << endl;
#define o(x)        for(auto a:x)cout << a <<" ";cout << endl;
#define o2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cout << x[i][j] << " ";cout << endl; } 
#define i(x,n)      for(int i=0;i<n;i++)cin >> x[i];
#define i2(x,n,m)   for(int i =0;i<n;i++){for(int j=0;j<m;j++)cin >> x[i][j]; }
int inf = 1e18;
const int Max = 3005;
int dp[Max][Max];

vi a;
void solve(int l,int r)
{
    if(l == r)
    {
        dp[l][r] = a[l];
        return ;

    }

    if(dp[l][r] == -1)
    {
        solve(l+1,r);
        solve(l,r-1);
    }

   
    dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
    return ;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin >> n;
    a.resize(n);i(a,n);


    for(int i=0;i<Max;i++)
    {
        for(int j=0;j<Max;j++)dp[i][j] = -1;
    }

   
    solve(0,n-1);


    deb(dp[0][n-1]);
}

