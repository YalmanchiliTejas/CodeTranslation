#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100000],dp[100000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    fill(dp,dp+n,1000000007);
    for(int i=n-1;i>=0;i--){
        *upper_bound(dp,dp+n,a[i])=a[i];
    }
    cout<<lower_bound(dp,dp+n,1000000007)-dp<<endl;
}