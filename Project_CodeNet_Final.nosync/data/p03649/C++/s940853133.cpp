#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define endl '\n'
using namespace std;
const int N=60;
ll a[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll ans=0;
    while(true){
        ll p1=0;
        for (int i=1;i<=n;i++){
            if (a[i]>=n){
                ll z=a[i]/n;
                a[i]=a[i]%n;
                for (int j=1;j<i;j++) a[j]+=z;
                for (int j=i+1;j<=n;j++) a[j]+=z;
                ans+=z;
            }
        }
        for (int i=1;i<=n;i++) if (a[i]>=n) p1=1;
        if (!p1) break;
    }
    cout << ans << endl;
}
