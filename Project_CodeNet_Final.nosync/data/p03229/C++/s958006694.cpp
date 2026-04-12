#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define all(i) begin(i), end(i)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    ll ans = a[n-1] - a[0];
    rep(i,1,n/2){
        ans += a[n - i] - a[i];
        ans += a[n-i-1] - a[i-1];
    }
    if(n & 1) ans += max(a[n/2] - a[n/2 - 1],a[n-n/2] - a[n/2]);
    cout << ans << endl;
}