#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    reverse(a,a+n);
    int dp[n+1];
    fill(dp,dp+n+1,INF);
    for(int i=0;i<n;i++){
        if(dp[i]<=a[i]){
            dp[i+1]=a[i];
        }else{
            int idx=upper_bound(dp,dp+n+1,a[i])-dp;
            dp[idx]=a[i];
        }
    }
    cout<<lower_bound(dp,dp+n+1,INF)-dp<<endl;
}