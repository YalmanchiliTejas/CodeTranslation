#include<bits/stdc++.h>
#define fr(i,c,b) for(int i=c;i<b;i++)
#define frl(i,c,b) for(ll i=c;i<b;i++)
#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl printf("\n")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MAX 100001
#define M 1000000007
#define pb push_back

typedef long long int ll;

using namespace std;

int main()
{
    sll(n);
    ll a[n]; fr(i,0,n)  cin>>a[i];
    ll sum[n];
    sum[n-2]=a[n-1];
    for(int i=n-3;i>=0;i--)
    {
        sum[i]=(sum[i+1]%M+a[i+1]%M)%M;
    }
    
    ll ans=0;
   // ll j=n-2;
    for(int i=0;i<n-1;i++)
    {
        ans=(ans%M+a[i]%M*sum[i]%M)%M;
    }
    
    cout<<ans%M;
    
    
    
}
