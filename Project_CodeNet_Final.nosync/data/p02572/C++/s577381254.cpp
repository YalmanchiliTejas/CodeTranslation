#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 200000;
ll mod = INF;
ll sum[maxn];
ll a[maxn];
ll ans=0;
int n;

int main(){
    
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    sum[0]=a[0];
    for(int i=1;i<n;i++)sum[i]=(sum[i-1]+a[i])%mod;

    for(int i=0;i<n;i++){
        ll temp=sum[n-1]-sum[i];
        while(temp<0)temp+=INF;
        ans=(ans+a[i]*temp%mod)%mod;
    }

    cout << ans<<endl;
    return 0;
}