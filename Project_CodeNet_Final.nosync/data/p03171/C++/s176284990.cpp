#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 3005

int n;
ll *arr, dp[MAX][MAX];

ll solve(int i, int j){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    ll opt1 = arr[i]-solve(i+1, j);
    ll opt2 = arr[j]-solve(i, j-1);

    return dp[i][j] = max(opt1, opt2);
}

void topDown(){
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n-1)<<endl;
}

int main(){
    fstIO;
    cin>>n;
    arr = new ll[n+1];
    ip(arr, n);
    topDown();
    return 0;
}
