#include <bits/stdc++.h>
using namespace std;

const int nax = 3005;
int main()
{
    int n;
    cin>>n;
    long long dp[nax][nax];
    vector<int> a(n);
    for(int& x: a){
        scanf("%d",&x);
    }
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r)
                dp[l][r] = a[l];
            else{
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
    //cout<<dp[0][n-1];
}
