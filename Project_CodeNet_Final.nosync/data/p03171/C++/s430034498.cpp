#include "bits/stdc++.h"
using namespace std;
#define F first
#define S second
#define show(x) cout<<#x<<" "<<x<<" ";
#define f(i,j,k) for(int i = j;i<=k;i++)
#define fr(i,j,k) for(int i = j;i>=k;i--)
#define ll long long
#define all(A)  A.begin(),A.end()  
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);  
const int MSIZE = 3e3+5;
const int MOD = 1e9+7;


int arr[MSIZE];
ll dp[MSIZE][MSIZE];

ll solve(int i,int j,int &n) {
    if(i>j) return 0;
    if(dp[i][j]!=-1)    return dp[i][j];
    ll l = solve(i+1,j,n), r = solve(i,j-1,n);
    return dp[i][j] = (n-j+i)%2?max(arr[i]+l,arr[j]+r)
                                :min(-arr[i]+l,-arr[j]+r);
}

int main(){
    
    FIO
    int n; cin>>n;
    f(i,0,n-1)    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,n-1,n)<<endl; 
    return 0;

}
    
