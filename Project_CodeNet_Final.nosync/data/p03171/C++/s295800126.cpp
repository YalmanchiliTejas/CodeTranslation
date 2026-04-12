#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
ll dp[3001][3001];

ll solve(vector<int>& arr, int i, int j)
{
    if(i>j) return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll opt1= arr[i]+ min(solve(arr, i+1, j-1), solve(arr, i+2, j));
    ll opt2= arr[j]+ min(solve(arr, i, j-2), solve(arr, i+1, j-1));
    return dp[i][j]=max(opt1, opt2);
}

int main()
{
    FASTIO;
    int n;
    ll sum=0;
    cin>>n;
    memset(dp, -1, sizeof dp);
    vector<int> arr(n+1);
    loop(i,1, n+1){
        cin>>arr[i];
        sum+=arr[i];
    }
    ll x=solve(arr, 1, n);
    cout<<2*x-sum;
    return 0;
}


