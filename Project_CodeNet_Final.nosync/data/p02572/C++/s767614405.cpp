#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
typedef pair<int,int> P;
struct edge{int to, id;};
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007
 
using graph = vector<vector<ll>>;

int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll sum[n];
    //sum[0] = 0;
    rep(i,n){
        ll temp;
        cin >> temp;
        a[i] = temp;
    }
    sum[n-2] = a[n-1];
    for(int i = n-3; i >= 0; i--){
        sum[i] = (sum[i+1] + a[i+1]) % mod;
    }
    ll ans = 0;
    rep(i,n-1){
        ans += a[i] * sum[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
    
}