#include <bits/stdc++.h>

using namespace std;
const int N=2e5+10;
const int MOD=1e9+7;
typedef long long ll;
ll a[N];
ll pre[N];
ll dp[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[1]=a[1];
    for(int i=3;i<=n;i+=2) pre[i]=pre[i-2]+a[i];
    //dp[1]=a[1];
    for(int i=2;i<=n;i++){


        if(i%2){
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        else{
            dp[i]=max(dp[i-2]+a[i],pre[i-1]);
        }
        }

    cout<<dp[n]<<endl;
}
