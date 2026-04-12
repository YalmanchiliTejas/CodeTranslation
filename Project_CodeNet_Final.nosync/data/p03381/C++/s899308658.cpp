#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    vector<pair<int,int>> xs;
    rep(i,0,n) xs.emplace_back(a[i],i);
    sort(all(xs));
    vi ans(n);
    vi c(n);
    rep(i,0,n) {
        c[i]=xs[i].second;
    }
    rep(i,0,n/2) {
        ans[c[i]]=xs[n/2].second;
    }
    rep(i,n/2,n) {
        ans[c[i]]=xs[n/2-1].second;
    }
    rep(i,0,n) cout<<a[ans[i]]<<"\n";
}
