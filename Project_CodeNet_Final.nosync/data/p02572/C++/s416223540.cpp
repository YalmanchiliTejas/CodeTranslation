#include <bits/stdc++.h>
#define mod 1000000007
#define nl cout<<"\n"
#define fr(n) for(int i = 0; i<n; i++)
#define frr(j, n) for(int i = j; i<n; i++)
#define Mem(x) memset(x, 0, sizeof(x))
using namespace std;
typedef long long int lli;
int main(){
    lli n;
    cin>>n;
    lli a[n];
    lli ans = 0;
    fr(n){
        cin>>a[i];
        ans += a[i];
    }
    lli ans2 = 0, k;
    fr(n-1){
        ans -= a[i];
        k = ans%mod;
        k *= a[i];
        k %= mod;
        ans2 += k;
    }
    cout<<ans2%mod;
    return 0;
}