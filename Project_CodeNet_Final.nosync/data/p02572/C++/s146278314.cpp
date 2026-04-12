#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main(void){
    int n;
    cin >> n;
    vector <ll> a(n);
    REP(i,n) cin >> a[i];
    ll ans=0;
    ll x=0;
    REP(i,n){
        ans=(ans+a[i]*x)%MOD;
        x=(x+a[i])%MOD;
    }
    cout << ans << endl;
    return 0;
}