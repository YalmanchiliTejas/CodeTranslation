#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(vec) vec.begin(), vec.end()
#define tmax(x,y,z) max((x),max((y),(z)))
#define tmin(x,y,z) min((x),min((y),(z)))
typedef long long ll; ll MM = 1000000000;ll mod = MM + 7; ll MMM=9223372036854775807;//2^63 -1
ll GCD(ll x, ll y) {if (y == 0) return x;else return GCD(y, x % y);}
ll LCM(ll x, ll y) { return x / GCD(x, y) * y;}
//cout << fixed << setprecision(10);
ll fac(ll x){if(x==0) return 1;  return x*fac(x-1);}

int main(){
    ll n,m; cin>>n>>m;
    if(n==m) cout<<"Yes";
    else cout<<"No";
}