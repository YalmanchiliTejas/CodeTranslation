#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

ll M= 1000000007;

int main() {

    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) {
        cin>>v[i];
    }

    vector<ll> sumv;
    ll sum=0;
    for(ll i=n-1;i>0;i--) {
        sum+=v[i];
        sumv.pb(sum);
    }
    reverse(sumv.begin(),sumv.end());


    ll ans=0,res=0;
    for(ll i=0;i<n-1;i++) {
        ll a=v[i];
        ll b=sumv[i];
        ans=((a % M) * ( b % M))%M;
        res+=ans;
        res=res%M;
    }
    res=res%M;

    cout<<res<<endl;

    return 0;

}