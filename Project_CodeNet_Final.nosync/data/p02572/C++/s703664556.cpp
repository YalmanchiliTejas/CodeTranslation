#include<bits/stdc++.h>
#define ll long long
#define loop(a,b) for(ll i=a;i<b;i++)
#define iloop(a,b) for(int i=a;i<b;i++)
#define it(c) for(auto it=c.begin();it!=c.end();it++)
#define M 1000000007

using namespace std;

void Thai_Jase() {
    ll n;
    cin>>n;
    ll a[n],sum=0,ans=0;
    loop(0,n) {
        cin>>a[i];
        sum+=a[i];
    }
    for(ll i=0;i<n-1;i++) {
        ll temp=(sum-a[i])%M;
        ans+=(a[i]*temp)%M;
        sum-=a[i];
    }
    cout<<ans%M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ts=1;
    while(ts--) {
      Thai_Jase();
    }
    return 0;
}