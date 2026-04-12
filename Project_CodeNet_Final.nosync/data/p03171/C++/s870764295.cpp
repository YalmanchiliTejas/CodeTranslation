#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <math.h>
#include <climits>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define ld long double
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define mii map<int,int>
#define msi map<string,pair<int,int>>
#define pii pair<int,int>
#define F first
#define S second
#define PI 3.1415926535
typedef long long ll;
using namespace std;
ll dp[10000][10000];
ll solve(int i,int j,ll arr[])
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==j)
    return arr[i];
    if(j==i+1)
    return max(arr[i],arr[j]);
    dp[i][j]=max((arr[i]+min(solve(i+2,j,arr),solve(i+1,j-1,arr))),(arr[j]+min(solve(i,j-2,arr),solve(i+1,j-1,arr))));
    return dp[i][j];
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f(i,10000)
    {
        f(j,10000)
        dp[i][j]=-1;
    }
    ll n;
    cin>>n;
    ll arr[n];
    ll sum=0;
    f(i,n)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    ll r=solve(0,n-1,arr);
    ll a=sum-r;
    ll b=r-a;
    cout<<b<<endl;
}
