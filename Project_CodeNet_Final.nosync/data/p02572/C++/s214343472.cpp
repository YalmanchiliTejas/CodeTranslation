#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    int n; cin>> n;
    vector<ll> a(n);
    vector<ll> b(n + 1, 0);
    int mod = 1000000007;

    rep(i, n){
        cin>> a[i];
        b[i + 1] = b[i] + a[i];
    }

    ll ans = 0;
    rep(i, n){
        ll sum = (b[n] - b[i+1]) % mod;
        ans += a[i] * sum;
        ans %= mod;
    }
    cout<< ans << endl;
}
