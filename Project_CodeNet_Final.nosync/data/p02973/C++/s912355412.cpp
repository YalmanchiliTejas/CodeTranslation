#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=2e9;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n];
    fill(dp,dp+n,INF);
    for(int i=n-1;i>=0;--i){
        *upper_bound(dp,dp+n,a[i])=a[i];
    }
    cout<<lower_bound(dp,dp+n,INF)-dp<<endl;
}
