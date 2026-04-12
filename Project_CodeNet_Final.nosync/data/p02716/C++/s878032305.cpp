#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[200005];
ll pre[200005];
ll suf[200005];

void solveeven(){
    pre[1]=a[1];
    pre[2]=a[2];
    suf[n]=a[n];
    suf[n-1]=a[n-1];
    for(int i=3;i<=n;i++)pre[i]=pre[i-2]+a[i];
    for(int i=n-2;i>=1;i--)suf[i]=suf[i+2]+a[i];
    ll res=max(pre[n-1],suf[2]);
    for(int i=1;i+3<=n;i+=2){
        res=max(res,pre[i]+suf[i+3]);
    }
    cout<<res<<endl;
}

ll dp[200005][3];

void solveodd(){
    dp[1][0]=a[1];
    for(int i=2;i<=n;i++){
        dp[i][0]=dp[i-2][0]+a[i];
        dp[i][1]=max(dp[i-2][1],dp[i-1][0]-a[i-1])+a[i];
        dp[i][2]=max(max(dp[i-2][2],dp[i-2][0]-a[i-2]),dp[i-1][1]-a[i-1])+a[i];
    }
    cout<<max(dp[n-2][0],max(dp[n][2],dp[n-1][1]))<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n&1){
        solveodd();
    }else{
        solveeven();
    }

    return 0;
}