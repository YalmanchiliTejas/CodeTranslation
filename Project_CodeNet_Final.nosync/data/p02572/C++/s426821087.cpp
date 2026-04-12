#include <iostream>
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

long long ncr(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
ll mod(ll a,ll b,ll m){
    if(b==0)return 1;
    if(b%2==0){
        ll y =  mod(a,b/2,m);
        return (y*y)%m;
    }
    else{
        return ((a%m)*mod(a,b-1,m))%m;
    }
}

ll modinv(ll a,ll m){
return mod(a,m-2,m);
//works only for prime m.
//else calculate phi(m)-1.
}

const ll m=1e9+7;

int main()
{
    int n;
    cin>>n;
    vector<ll>a(n),pref(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        pref[i]=sum;

    }
    ll ans=0;
for(int i=0;i<n-1;i++){
    ll p=a[i];
    ll q = pref[n-1]-pref[i];
    ll z= ((p%m)*(q%m))%m;
    ans=((ans%m)+(z%m))%m;
}
cout<<ans<<endl;
    return 0;
}
