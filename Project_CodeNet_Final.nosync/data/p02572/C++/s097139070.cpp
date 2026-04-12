#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll m = 1000000007;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin>>n;

    ll sum = 0;

    vector<ll>v(n);
    for(ll &x:v)cin>>x,sum+=x;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        sum = sum - v[i];

        ans = (ans%m + (sum%m * v[i]%m)%m)%m;

    }

    cout<<ans;

    return 0;

}

