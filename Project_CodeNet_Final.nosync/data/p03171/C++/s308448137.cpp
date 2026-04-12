#include<bits/stdc++.h>
#define for0(n) for(int i=0; i<n; i++)
#define _int64 long long int
using namespace std;
const int N = 3100;
_int64 dp[N][N];

_int64 max_diff(int i, int j, const _int64 arr[]){
    if(dp[i][j]!= -1)
        return dp[i][j];
    if(i==j)
        return dp[i][j] = arr[i];
    else if(i > j)
        return dp[i][j] = 0;
    return dp[i][j] = max(arr[i]-max_diff(i+1, j, arr), arr[j]-max_diff(i, j-1, arr));
}

int main(){
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    _int64 arr[N];
    for0(n) cin >> arr[i];
    cout << max_diff(0, n-1, arr) << endl;
}
