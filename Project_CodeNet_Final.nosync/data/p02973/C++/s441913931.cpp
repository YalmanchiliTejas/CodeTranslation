#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 998244353;
using ll = long long;
using P = pair<ll, ll>;
double PI = acos(-1);

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    deque<int> d;

    rep(i,n) {
        int p = lower_bound(d.begin(), d.end(), a[i])- d.begin();
        if(p==0) {
            d.push_front(a[i]);   
        }else {
            d[p-1]=a[i];
        }
    }

    cout << d.size() << endl;
    
    return 0;
}

