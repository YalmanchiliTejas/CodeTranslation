#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#define io ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
ll a[maxn],pre[maxn];//,sum[maxn];
const int mod=1e9+7;
void solve(){
     int n;cin>>n;
    //ll sum=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    //sort(a+1,a+1+n);
    //pre[0]=0;
    for(int i=1;i<=n;i++){pre[i]=pre[i-1]+a[i];}
    ll ans=0;
    for(int i=1;i<n;i++){
        ans=(ans+((pre[n]-pre[i])%mod)*a[i]%mod)%mod;
    }
    cout<<ans%mod;
}
int main(){
    io;
    //int T;cin>>T;
    //while(T--)
        solve();
}
