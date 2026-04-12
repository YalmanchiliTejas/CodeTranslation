#include <bits/stdc++.h>
#define LL               long long int
#define PB               push_back
using namespace std;
LL M= 1000000000+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;cin>>n;
    LL a[n];
    LL dp[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (i==0) dp[i]=a[i];
        else {
            dp[i]=dp[i-1]+a[i];
            dp[i]%=M;
        }
    }
    LL ans=0;
    for (int i=1;i<n;i++){
        ans+=dp[i-1]*a[i];
        ans%=M;
    }
    cout<<ans<<"\n";
}