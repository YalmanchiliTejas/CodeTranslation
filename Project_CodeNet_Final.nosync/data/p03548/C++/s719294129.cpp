#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;i++)
typedef long long int ll;

int main(){

    ll x,y,z;

    cin >> x >> y >> z;

    x-=z;
    ll ans = x/(y+z);
    cout << ans << endl;

    return 0;
}