#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;
const ll mod=1e9+7;
const ll N=200005;
int main()
{
    ll n;
    cin>>n;
    int a[N],b[N];
    ll ans=0;
    a[0]=0;
    b[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=(b[i-1]+a[i])%mod;
    }
    for(int i=1;i<n;i++){
        ans=(ans+((b[n]-b[i]+mod)%mod)*a[i])%mod;
    }
    cout<<ans<<endl;
}