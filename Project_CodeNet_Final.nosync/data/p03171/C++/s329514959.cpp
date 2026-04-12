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

int main(){

    FIO
    int n; cin>>n;
    f(i,0,n-1)    cin>>arr[i];
    
    f(i,0,n-1)  dp[i][i] = n%2?arr[i]:-arr[i];
    f(k,1,n-1) for(int i=0, j = k; j<n; i++, j++) {
        dp[i][j] = (n-j+i)%2?max(arr[i]+dp[i+1][j],arr[j]+dp[i][j-1])
                                :min(-arr[i]+dp[i+1][j],-arr[j]+dp[i][j-1]);
    }
    // f(i,0,n-1){ 
    //     f(j,0,n-1)  cout<<dp[i][j]<<" ";  cout<<endl; 
    // }
    cout<<dp[0][n-1]<<endl; 
    return 0;

}
    
