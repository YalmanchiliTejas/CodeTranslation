#include<bits/stdc++.h>
#include <bitset>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define dcm(a) setprecision(a)<<fixed
#define MOD 1000000007
#define clr(memo, a) memset(memo,a,sizeof(memo))
#define PI acos(-1)
int const N=3e3+5;
ll dp[N][N];
void solve()
{
int n;
cin>>n;
vector<int> a(n+1);
for(int i=0;i<n;i++)
    cin>>a[i];
for(int i=n-1;i>=0;i--)
for(int j=i;j<n;j++){
    if(i==j)
        dp[i][j]=a[i];
    else
        dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
}
cout<<dp[0][n-1]<<endl;
}
int main()
{
    fast;
    solve();

    return 0;
}
