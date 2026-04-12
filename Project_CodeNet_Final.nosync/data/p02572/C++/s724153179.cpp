#include<bits/stdc++.h>
#define cases long long t;cin>>t;while(t--)
#define f_io ios::sync_with_stdio(false); cin.tie(0)
#define foi(a,n) for(long long i=a;i<n;i++)
#define foj(a,n) for(long long j=a;j<n;j++)
#define fok(a,n) for(long long k=a;k<n;k++)
#define ll long long
#define MOD 1000000007
#define INF 1000000000
using namespace std;

int main()
{
    f_io;
    ll n;
    cin >> n;
    vector<ll> arr(n),pre(n);
    foi(0,n)
        cin >> arr[i];
    pre[n-1]= arr[n-1];
    for(ll i = n-2;i>=0;i--)
        pre[i]=(pre[i+1]+arr[i])%MOD;
    ll ans = 0;
    foi(0,n-1)
        ans = (ans + (arr[i]*pre[i+1])%MOD)%MOD;
    cout << ans;
    return 0;
}
