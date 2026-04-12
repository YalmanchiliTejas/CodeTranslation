#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

#define Make(x,p)       (x  (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

int n;
LL arr[3003];
LL dp[3003][3003];
bool vis[3003][3003];

LL call(int i,int j){
    if(i==j) return arr[i];
    if(vis[i][j]==1) return dp[i][j];
    vis[i][j]=1;
    return dp[i][j]=max(arr[i]-call(i+1,j),arr[j]-call(i,j-1));
}

int main()
{
    cin >> n;
    REP(i,n) cin >> arr[i];
    cout << call(0,n-1);
}
