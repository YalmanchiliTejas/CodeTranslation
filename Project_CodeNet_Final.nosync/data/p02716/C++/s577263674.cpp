#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=2e5+5;
int a[N];
ll pre[N],suf[N];
ll dp[N][3];

void init();
void work();
int ca=1;
int main(){
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
//    init();
//    int T;cin>>T;
//    while(T--)
    work();
    return 0;
}
void work(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre[i]=a[i]+(i>=2?pre[i-2]:0);
    }
    for(int i=n;i;i--){
        suf[i]=a[i]+(i+2<=n?suf[i+2]:0);
    }
    ll ans=-1e18;
    if(n%2==0){
        ans=max(pre[n-1],pre[n]);
        for(int i=1;i+3<=n;i++) if(i&1) ans=max(ans,pre[i]+suf[i+3]);
    }
    else{
        ans=max(pre[n-1],pre[n-2]);
        ans=max(ans,max(suf[2],suf[3]));
        for(int i=1;i+4<=n;i++)if(i&1){
            ans=max(ans,pre[i]+suf[i+4]);
        }
        dp[0][0]=0,dp[0][1]=dp[0][2]=0xcfcfcfcfcfcfcfcf;
        for(int i=1;i<=n;i++){
            for(int j=0;j<3;j++) dp[i][j]=dp[max(0,i-2)][j]+a[i];
            if(i-3>=1) dp[i][1]=max(dp[i][1],dp[max(0,i-3)][0]+a[i]);
            if(i-3>=1) dp[i][2]=max(dp[i][2],dp[max(0,i-3)][1]+a[i]);
        }
//        cout<<"dp: "<<dp[n][2]<<endl;
        ans=max(ans,dp[n][2]);
    }
    cout<<ans;
}
