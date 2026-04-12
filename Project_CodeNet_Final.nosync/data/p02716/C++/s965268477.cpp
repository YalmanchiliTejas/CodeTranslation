#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
ll pre[maxn];
ll bsum[maxn],psum[maxn];
ll dp[maxn];
int main() {
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>pre[i];
    ll ans=0;
    for(int i=2;i<=n;i+=2) ans+=pre[i];
    psum[1]=pre[1];bsum[n]=pre[n];dp[n-3]=pre[n]+pre[n-3];
    for(int i=2;i<=n;i++) psum[i]=psum[i-2]+pre[i];
    for(int i=n-1;i>=1;i--) bsum[i]=bsum[i+2]+pre[i];
    if(n%2==0){
        ll a1=0,a2=0,ans;
        for(int i=1;i<=n;i++) if(i%2) a1+=pre[i];else a2+=pre[i];
        ans=max(a1,a2);
        for(int i=2;i<=n-1;i+=2) ans=max(ans,psum[i-1]+bsum[i+2]);
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n-1;i++) ans=max(ans,psum[i-1]+bsum[i+2]);
    for(int i=2;i<=n-3;i+=2) ans=max(ans,psum[i-1]+bsum[i+3]);
    for(int i=n-5;i>=2;i-=2) dp[i]=max(pre[i]+bsum[i+3],pre[i]+dp[i+2]);
    for(int i=2;i<=n-5;i+=2) ans=max(ans,psum[i-1]+dp[i+2]);
    cout<<ans<<endl;
    return 0;
}