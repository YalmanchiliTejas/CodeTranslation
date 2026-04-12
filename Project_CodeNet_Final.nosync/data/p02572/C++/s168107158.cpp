#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;

const ll mod = (ll)(1e9 + 7);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vll v(n);
    ll cur = 0;
    ll s = 0;

    for(ll i = 0; i < n; i++) cin >> v[i];

  	ll sum[n];
  	sum[0] = v[0];
  
    for(ll i = 1; i < n; i++){
        sum[i] = sum[i-1] + v[i];
    }

    for(ll i = 0; i < n; i++){
        cur = sum[n-1] - sum[i];

        s = ((s%mod) + (((v[i]%mod)*(cur%mod))%mod)%mod)%mod;
    }

    cout << s;


    return 0;
}
