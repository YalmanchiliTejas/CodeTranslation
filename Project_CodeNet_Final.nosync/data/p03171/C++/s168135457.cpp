#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, a[3005], dp_mx[3005][3005], dp_mn[3005][3005];

ll f(ll i, ll j){

    if(i > j) return 0;
    if(i == j+1) return dp_mx[i][j] = max(a[i], a[j + 1]) - min(a[i], a[j + 1]);

    if(dp_mx[i][j] != -1) return dp_mx[i][j];

    ll p = a[i] + min(f(i+2,j), f(i+1,j-1));
    ll q = a[j] + min(f(i+1, j-1), f(i, j-2));

    return dp_mx[i][j] = max(p,q);
}

ll g(ll i, ll j){

    if(i > j) return 0;
    if(i == j+1) return dp_mn[i][j] = max(a[i], a[j + 1]) - min(a[i], a[j + 1]);

    if(dp_mn[i][j] != -1) return dp_mn[i][j];

    ll p = a[i] + min(f(i+2,j), f(i+1,j-1));
    ll q = a[j] + min(f(i+1, j-1), f(i, j-2));

    return dp_mn[i][j] = max(p,q);
}

int main() {

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin>>n;
    for(ll z=0;z<n;z++) cin>>a[z];

    memset(dp_mx, -1, sizeof dp_mx);

    ll j = f(0,n-1);
    ll j1 = f(1,n-1), j2 = f(0, n-2);
    if(j1 < j2) cout<<j - j1;
    else cout<<j - j2;




    return 0;
}