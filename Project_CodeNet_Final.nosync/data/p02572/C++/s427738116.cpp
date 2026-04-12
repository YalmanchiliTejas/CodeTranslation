#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define inf 1e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
    ll n,sum=0,ans=0,a[200000]={};
    cin>>n;
    REP(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    sum%=1000000007;
    REP(i,n){
        sum-=a[i];
        sum=(ll)(sum+1e9+7)%(ll)(1e9+7);
        ans+=a[i]*sum;
        if(ans>=1000000007) ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}