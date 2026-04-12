#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<ll>a(n),b, c;
    rep(i, 0, n)cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    rep(i, 0, n/2)b.push_back(a[i]);
    rep(i, n/2, n)c.push_back(a[i]);
    ll ans=0,sumb=0,sumc=0;
    rep(i, 0, b.size())sumb += b[i];
    rep(i, 0, c.size())sumc += c[i];
    ans = (sumb-sumc)*2;
    ll ans2 = ((sumb+c[0])-(sumc-c[0]))*2;
    //cout << sumb << sumc << endl;
    if(n%2==0){
        cout << ans-b[b.size()-1]+c[0] << endl;
        return 0;
    }else{
        ll ansa = ans + c[0] + c[1];
        ll ansb = ans2 - c[0] - b[b.size()-1]; 
        //cout << ansa << " " << ansb << endl;
        cout << max(ansa, ansb) << endl;
        return 0;
    }
}