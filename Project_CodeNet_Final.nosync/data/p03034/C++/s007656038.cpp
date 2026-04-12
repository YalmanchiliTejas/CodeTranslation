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
//const int mod = 998244353;
const int N = 2000005;
const int K = 1000000;
vector < int > ls[N], rs[N];
int s[N], n;
int check(int A, int delta){
    int m = (n - A - 1) / delta;
    if (delta >= A) return -1;
    if (A % delta == 0){
        if (A / delta <= m) return -1;
        return ls[delta][m] + rs[delta][m];
    }
    return ls[delta][m] + rs[delta][m];
}
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 1; i < n; i++){
        ls[i].pb(0);
        rs[i].pb(0);
        for (int j = i; j < n; j += i){
            int x = ls[i].back();
            ls[i].pb(x + s[j]);
        }
        for (int j = n - 1 - i; j >= 0; j -= i){
            int x = rs[i].back();
            rs[i].pb(x + s[j]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++){
        int d = n - i - 1;
        for (int j = 1; j * j <= d; j++){
            if (d % j != 0) continue;
            ans = max(ans, check(i, j));
            ans = max(ans, check(i, d / j));
        }
    }
    cout << ans;
}
