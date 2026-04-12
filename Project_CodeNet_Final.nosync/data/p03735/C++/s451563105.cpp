#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define F first
#define S second
#define int long long
#define ll long long
//#define int  unsigned long long
#define pb push_back
//#define double long double

using namespace std;
using namespace __gnu_pbds;
typedef  tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int mod = 1e9 + 7;
const int N = 200005;
const int K = 50;
pair < int, int > a[N];
vector < pair < int, int > > b;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].F >> a[i].S;
        if (a[i].S > a[i].F) swap(a[i].F, a[i].S);
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int rmax = a[1].F;
    int rmin = a[1].F;
    int bmax = a[1].S;
    int bmin = a[1].S;
    int ans = 2e18;
    int p = 1;
    int x = a[1].S;
    for (int i = 2; i <= n; i++){
        if (x > a[i].S){
            p = i;
            x = a[i].S;
        }
        if (x > a[i].F){
            p = -i;
            x = a[i].F;
        }
    }
    if (p == 1){
        bmin = x;
       for (int i = 2; i <= n; i++){
            if (a[i].F > a[i].S) swap(a[i].F, a[i].S);
            rmin = min(rmin ,a[i].S);
            bmax = max(bmax, a[i].F);
       }
       ans = (rmax - rmin) * (bmax - bmin);
       cout << ans;
       return 0;
    } else{
        if (p < 0){
            bmin = a[-p].F;
            rmin = min(rmin, a[-p].S);
        }
        else{
            bmin = a[p].S;
            rmin = min(rmin, a[p].F);
        }
        p = abs(p);
        for (int i = 2; i <= n; i++){
            if (i == p) continue;
            if (a[i].F > a[i].S) swap(a[i].F, a[i].S);
            rmin = min(rmin ,a[i].S);
            bmax = max(bmax, a[i].F);
       }
       ans = (rmax - rmin) * (bmax - bmin);
    }
    rmax = a[1].F;
    rmin = x;
    int y;
    if (p < 0) y = a[-p].S; else y = a[p].F;
    bmax = max(a[1].S, y);
    bmin = min(a[1].S, y);
    for (int i = 2; i <= n; i++){
        if (i == p) continue;
        if (a[i].F < bmin && a[i].S < bmin){
            bmin = max(a[i].F, a[i].S);
        } else
        if (a[i].F > bmax && a[i].S > bmax){
            bmax = min(a[i].F, a[i].S);
        } else
        if (a[i].F <= bmax && a[i].F >= bmin) continue; else
        if (a[i].S <= bmax && a[i].S >= bmin) continue; else
        if (a[i].F > a[i].S){
            swap(a[i].F, a[i].S);
            b.pb({a[i].F, a[i].S});
        } else b.pb({a[i].F, a[i].S});
    }
    sort(b.begin(), b.end());
    if (b.empty()){
        ans = min(ans, (rmax - rmin) * (bmax - bmin));
    } else{
        int rb = bmax;
        for (int i = 0; i < b.size(); i++){
            ans = min(ans, (rmax - rmin) * (max(rb, bmax) - min(b[i].F, bmin)));
            rb = max(rb, b[i].S);
        }
    }
    cout << ans;
}
