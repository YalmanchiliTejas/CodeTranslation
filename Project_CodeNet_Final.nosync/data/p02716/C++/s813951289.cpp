#pragma GCC optimize("O3")
#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<pii>
#define read(FILE)  freopen(FILE, "r", stdin);
#define out(FILE) freopen(FILE, "w", stdout);
#define clr(x, y) memset(x,y,sizeof(x));
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define rep(i, m, n) for(int i=m ; i<n ; i++)
#define forr(i, m, n) for(ll i=m ; i<=n ; i++)
#define endl '\n'
#define pb push_back
#define re return
const int N = 2e5 + 5;
const ll OO = 1e9+7;
using namespace std;
ll n;
ll arr[N];
ll dp[N][3];
ll knap1(ll i ,ll c)
{
    if(i>=n)
        return 0;
    if(dp[i][c]!=LONG_LONG_MAX)
        return dp[i][c];
    if(c==0)
        return dp[i][c]=max(arr[i]+knap1(i+2,0),max(arr[i+1]+knap1(i+3,1),arr[i+2]+knap1(i+4,2)));
    if(c==1)
        return dp[i][c]=max(arr[i]+knap1(i+2,1),arr[i+1]+knap1(i+3,2));
    else
        return dp[i][c]=arr[i]+knap1(i+2,2);
}
ll knap(ll i ,ll c)
{
    if(i>=n)
        return 0;
    if(dp[i][c]!=LONG_LONG_MAX)
        return dp[i][c];
    if(c==0)
        return dp[i][c]=max(arr[i]+knap(i+2,0),arr[i+1]+knap(i+3,1));
    else
        return dp[i][c]=arr[i]+knap(i+2,1);
}
int main()
{
    cin>>n;
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    rep(i,0,N){
        rep(j,0,3){
            dp[i][j]=LONG_LONG_MAX;
        }
    }

    ll sum=0;
    if(n%2==0)
        cout<<knap(0,0);
    else
        cout<<knap1(0,0);
    return 0;
}
