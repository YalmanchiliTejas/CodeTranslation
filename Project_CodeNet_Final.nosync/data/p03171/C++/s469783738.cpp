
#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define int long long
int dp[3000][3000][2];
int ar[3000];
int n;
int recur(int i, int j, int p)
{
    p=p%2;
    if(j<i || min(i,j)<0 || max(i,j)>n)
        return 0;
    if(dp[i][j][p])
        return dp[i][j][p];
    int t = max(ar[i], ar[j]);
    if(p == 0)
        dp[i][j][p] = max(ar[i] + recur(i+1,j,p+1),  ar[j] + recur(i,j-1,p+1));
    else
        dp[i][j][p] = min(recur(i+1,j,p+1) - ar[i], recur(i,j-1,p+1)-ar[j]);
    return dp[i][j][p];
}



signed main()
{
    IOS
    cin >> n;
    REP(i, n)
        cin >> ar[i];
    
    cout << recur(0,n-1,0);
    
}