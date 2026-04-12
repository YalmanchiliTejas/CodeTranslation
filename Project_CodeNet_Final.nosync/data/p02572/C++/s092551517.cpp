#include<iostream>
#include<vector>
#define rep(i,n) for(ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    const ll INF = 1e9 + 7;
    ll n, sum = 0, ans = 0;
    cin >> n;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
        a[i] = a[i] % INF;
        sum += a[i];
    }
    rep(i,n){
        sum -= a[i];
        ans += ((a[i] % INF) * (sum % INF)) % INF; 
    }
    cout << ans % INF << endl;
    return 0;
}