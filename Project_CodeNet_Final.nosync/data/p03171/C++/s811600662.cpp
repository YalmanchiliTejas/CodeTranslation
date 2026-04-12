#include <bits/stdc++.h>
#include <cstring>
#include <map>
#include <set>
#define int long long int
using namespace std;
const int MAX = 1000000007;

int dp[4000][4000];

signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
    #endif
    
    int n, i, l, r;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(l=n-1;l>=0;l--){
        for(r=l;r<n;r++){
            if(l==r)
                dp[l][r]=a[l];
            else
                dp[l][r]=max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    
}
