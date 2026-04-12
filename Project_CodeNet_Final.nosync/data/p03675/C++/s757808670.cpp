#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define otp(n) cout << n;
#define ct(n) cout << n << endl;
#define cts(n) cout << n << " ";
#define cte cout << endl;
#define ctv(v) rep(i,(v).size()) ct(v[i])
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repo(i,o,n) for(int i=o;i<n;i++)
#define repm(i,n) for(int i=n-1;i>=0;i--)
#define repv(i,v) for(int i=0;i<(v).size();i++)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end());
#define vdelete(v) (v).erase(unique(all(v)), (v).end());
#define pb(n) push_back(n);

int n,a[200000];
vector<int> v;

main() {
    cin >> n;
    rep(i,n) cin >> a[i];
    int k=n-1,f=(n+1)/2;
    rep(i,f) {
        v.pb(k)
        if(!k) {k=1;break;}
        if(k==1) {k=0;break;}
        k-=2;
    }
    f=n/2;
    rep(i,f) {v.pb(k)k+=2;}
    rep(i,n) {
        if (i+1==n) ct(a[v[i]])
        else cts(a[v[i]])
    }
}