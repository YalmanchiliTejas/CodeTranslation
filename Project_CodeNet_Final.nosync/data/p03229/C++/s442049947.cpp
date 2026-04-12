#include"bits/stdc++.h"
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define eb emplace_back

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using P = pair<int, int>;

void Main() {
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    sort(rall(a));

    ll tot1 = 0, tot2 = 0;
    
    /*
        n = 4, n/2 = 2
        tot1 = p0 - p1 + p2 - p1 + p2 - p3 = p0 - 2p1 + 2p2 - p3
        tot2 = p1 - p0 + p1 - p2 + p3 - p2 = -p0 + 2p1 - 2p2 + p3
        n = 5, n/2 = 2
        tot1 = p0 - p1 + p2 - p1 + p2 - p3 + p4 - p3 = p0 - 2p1 + 2p2 - 2p3 + p4
        tot2 = p1 - p0 + p1 - p2 + p3 - p2 + p3 - p4 = -p0 + 2p1 - 2p2 + 2p3 - p4
    */
    
    if(n&1){
        rep(i, n){
            if(i < n/2 - 1) tot1 += 2 * a[i];
            else if(i == n/2 - 1 || i == n/2) tot1 += a[i];
            else tot1 -= 2 * a[i];
        }
        
        rep(i, n){
            if(i < n/2) tot2 += 2 * a[i];
            else if(i == n/2 || i == n/2 + 1) tot2 -= a[i];
            else tot2 -= 2 * a[i];
        }
    }
    else{
        rep(i, n){
            if(i < n/2 - 1) tot1 += 2 * a[i];
            else if(i == n/2 - 1) tot1 += a[i];
            else if(i == n/2) tot1 -= a[i];
            else tot1 -= 2 * a[i];
        }
    }

    cout << max(tot1, tot2) << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}