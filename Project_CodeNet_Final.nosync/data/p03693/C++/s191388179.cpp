#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll INF = 1e18;
const  ll MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define repi(i,n,init) for(ll i=init;i<(n);i++)
#define repd(i,n,init) for(ll i=(n);i>=init;i--)
#define repm(i,m) for(auto i=m.begin();i!=m.end();i++)

int main()
{
    ll r,g,b;
    cin >> r >> g >> b;
    if((r*100 + g*10 + b) % 4 == 0){
        puts("YES");
    }else{
        puts("NO");
    }
    return 0;
}