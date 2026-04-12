#include<bits/stdc++.h>
using namespace std;
#define lson root<<1,l,midd
#define rson root<<1|1,midd+1,r
#define pb push_back
#define ull unsigned long long
#define pii pair<int,int>
#define MP make_pair
typedef long long ll;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
const int M=1e6+6;
const int mod=1e9+7;
ll a[M],f[M],F[M];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=n;i>=2;i--)
        f[i]=(f[i+1]+a[i])%mod;
    for(ll i=1;i<n;i++)
        F[i]=(F[i-1]+1ll*a[i]*f[i+1]%mod)%mod;
    cout<<F[n-1]<<endl;
    return 0;
}
