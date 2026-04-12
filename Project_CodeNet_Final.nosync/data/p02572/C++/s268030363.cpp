#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pii pair<ll,ll>

#define debug(a) { cout << #a << " = " << a << endl;}

const int maxn = 2e5+1;
ll arr[maxn],arr1[maxn], n, m, t, k;
unordered_map<ll,ll> u;

ll __min(ll a, ll b) {
    return a < b ? a : b;
}

ll __max(ll a, ll b) {
    return a > b ? a : b;
}

ll d(int i) {
    return arr[n-1] - arr[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>m;
        arr1[i]=m;
        if (i==0) arr[i] = m;
        else arr[i] = m+arr[i-1];
    }
    ll ans=0;
    for (int i=0;i<n;i++) {
        ans = (ans + ((arr1[i]%mod)*(d(i)%mod)))%mod;
    }
    cout << ans << "\n";
}
