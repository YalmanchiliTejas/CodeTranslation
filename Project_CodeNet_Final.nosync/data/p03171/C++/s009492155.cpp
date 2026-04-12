#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX =  3e3 + 10 ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m , x ,y, k , Q , ans ; string s,t;
ll a[MAX];
ll dp[MAX][MAX];

ll solve(int i , int j ){

    if(i > j)
        return 0;

    if(i == j)
        return a[i];

    ll &ret = dp[i][j];

    if(~ret)
        return ret;

    return ret = max(a[i] - solve(i + 1,j),a[j] - solve(i, j - 1));
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
 //   freopen("test.in","r",stdin);

    cin>>n;
    for(int i = 0 ; i < n ; ++i)
        cin>>a[i];

    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
                dp[i][j] = -1;

    cout<<solve(0,n - 1)<<'\n';
    return 0;
}
