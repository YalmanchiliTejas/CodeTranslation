#include <bits/stdc++.h> 
using namespace std; 
typedef long long l;
l f1(l* arr, l n) 
{ 
    l dp[n][n]; 
    for (l u = 0; u < n; ++u) { 
        for (l i = 0, j = u; j < n; ++i, ++j) { 
            l x = ((i + 2) <= j) ? dp[i + 2][j] : 0; 
            l y = ((i + 1) <= (j - 1)) ? dp[i + 1][j - 1] : 0; 
            l z = (i <= (j - 2)) ? dp[i][j - 2] : 0; 
            dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
    return dp[0][n - 1]; 
} 

int main() 
{ 
    l n;
    cin>>n;
    l arr[n];
    l sum = 0;
    for(l i = 0 ; i <n ; i++)
    {
    cin>>arr[i];
    sum+=arr[i];
    }
    l temp = f1(arr,n);
    cout<<(2*temp - sum);
    return 0; 
} 