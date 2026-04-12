#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;

void test_case(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    vector<vector<ll>>dp(n,vector<ll>(n));
    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            if(l==r){
                dp[l][r]=a[l];
                continue;
            }
            dp[l][r]=max(a[l]-dp[l+1][r], a[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}