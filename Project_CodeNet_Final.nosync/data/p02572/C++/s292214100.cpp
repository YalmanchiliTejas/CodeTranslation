#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb(x) push_back(x);
#define mp(x,y) make_pair(x,y)
#define mem(dp,a) memset(dp,a,sizeof dp);
#define all(a) a.begin(),a.end()
#define sall(a) sort(all(a))
#define X first
#define Y second
typedef long long int ll;
typedef pair<ll,ll> pp;

#define debug(x) cout << #x << " :: "<< x <<"\n";
#define debug2(x,y) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\n";
#define debug3(x,y,z) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\t" << #z << " :: " << z << "\n";
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree< pp , null_type,less< pp >, rb_tree_tag,tree_order_statistics_node_update>

ll power(ll b, ll exp){
    ll res = 1;
    while(exp > 0){
        if(exp % 2){
            res = 1LL * res * b % mod;
        }
        b = 1LL * b * b % mod;
        exp /= 2;
    }
    return res;
}

int main()
{
    boost
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans=0,sum=0;
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    for(ll i=0;i<n;i++) {
        sum-=a[i];
        ll temp=((sum%mod)*(a[i]%mod))%mod;
        ans = ( (ans%mod) + (temp%mod) )%mod;
    }
    cout << ans ;
    return 0;
}
