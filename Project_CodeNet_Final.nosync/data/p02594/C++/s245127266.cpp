#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define fr(a,b) for(ll i=a;i<b;i++)

const ll mod=1000000007;

ll powmod(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}

int32_t main(){
#ifdef _MSC_VER
    _CRT_SECURE_NO_WARNINGS
#endif
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
#pragma warning(suppress: 4101) srand(time(nullptr));
    cout << setprecision(20) << fixed;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
        ll n;
        cin>>n;
       int ans=n-30;
       if(ans>=0)
           cout<<"Yes\n";
       else
           cout<<"No\n";
    }