#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
ll INF = pow(10,9)+7;

int main(){
    ll ans = 0;
    ll n = 0;
    ll m,s;
    cin >> n;
    s = 0;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> m;
        s += m;
        s %= INF;
        v[i] = m;
    }
    for(int i=0;i<n;i++){
        ans += (v[i]*(s-v[i]))%INF;
        s -= v[i];
        s%=INF;
        ans = (ans+INF)%INF;
    }
    cout << ans;
}