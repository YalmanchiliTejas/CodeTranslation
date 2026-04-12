#include <bits/stdc++.h>
#define pb push_back
#define f first
#define sc second
using namespace std;
typedef long long int ll;
typedef string str;
const ll m = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector <ll> v(n);
    for(ll &x: v) cin >> x;
    vector <ll> sum(n);
    ll s = 0;
    for(int i = n - 2; i >= 0; i--){
        s+=v[i+1];
        s%=m;
        sum[i]=s;
    }
    ll ans  = 0;
    for(int i = 0; i < n- 1; i++){
        ans+=(v[i]*sum[i])%m;
        ans%=m;
    }
    cout << ans << "\n";
}
