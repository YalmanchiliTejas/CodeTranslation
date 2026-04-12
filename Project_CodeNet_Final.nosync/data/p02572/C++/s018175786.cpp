#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define pi  3.14159265359
#define mod 1000000007

int main()
{
    ll n;
    cin>>n;
    ll arr[n]; ll pre[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i==0){
            pre[i]=arr[i];
        }else{
        pre[i]=(pre[i-1]+arr[i]);
        }
    }
    ll ans=0;
    for(ll i=0;i<n-1;i++)
    {
        ans=(ans+(((pre[n-1]-pre[i])%mod*(arr[i]%mod))))%mod;

    }
    cout<<ans<<endl;

}
