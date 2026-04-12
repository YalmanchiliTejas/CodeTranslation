#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll M = 1e9 + 7;

ll mod(ll a){

    return ((a % M) + M) % M;
}
ll mul(ll a,ll b){

    return mod(mod(a)*mod(b));
}
ll add(ll a,ll b){

    return mod(mod(a) + mod(b));
}
int main(){

    //freopen("in.txt","r",stdin);

    ll n;

    cin >> n;

    vector< ll > v(n + 5),pfs(n + 5,0);

    for(int i = 0; i < n; i++) cin >> v[ i ];

    for(int i = n - 1; i >= 0; i--) pfs[ i ] = pfs[ i + 1 ] + v[ i ];

    ll sum = 0;

    for(int i = 0; i < n; i++) sum = add(sum,mul(v[ i ],pfs[ i + 1 ]));

    cout << sum << endl;

    return 0;
}

