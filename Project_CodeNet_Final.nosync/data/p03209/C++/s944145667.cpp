#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

ll dfs(ll n, ll x){
    if(x == 0) return 0;
    if(n == 0) return 1;
    ll a = pow((ll)2,(ll)(n+1));
    if(x <= a-2) return dfs(n-1,x-1);
    else return a/2 + dfs(n-1,min(a-3,x-a+1));
}

int main(){
    ll n, x;
    cin >> n >> x;
    ll ans = dfs(n,x);
    cout << ans << endl;
   return 0;
}