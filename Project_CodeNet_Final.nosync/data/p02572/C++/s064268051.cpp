#include <bits/stdc++.h>
#define rep( i, n ) for (ll i = 0; i < ( ll )(n); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > P;
typedef tuple<int, int, int> T;

int main(){
    ll n;
    const ll d=1000000007;
    ll sum=0;
    ll ans=0;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n){
        cin>>a[i];
        b[i]=a[i]%d;
        sum+=a[i];
    }

    rep(i,n-1){
        sum-=a[i];
        ans+=(b[i]*(sum%d))%d;
    }
    cout<<ans%d;
}
