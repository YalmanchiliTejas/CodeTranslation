/**
 *      purpose : ABC 115 D
 *      author  : kyomukyomupurin
 *      created : 2018-12-08 21:21:22
**/

#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using pii = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define print(x) cout << (x) << '\n'
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define fi first
#define se second

int64 a[55], p[55];

int64 rec(int64 n, int64 x){
    if (n == 0) return 1;
    if (x == 1) return 0;
    if (x > 1 && x <= 1 + a[n - 1]) return rec(n - 1, x - 1);
    else if (x == 2 + a[n - 1]) return p[n - 1] + 1;
    else if (x > 2 + a[n - 1] && x <= 2 + 2 * a[n - 1]) return p[n - 1] + 1 + rec(n - 1, x - a[n - 1] - 2);
    else if (x == 3 + 2 * a[n - 1]) return 2 * p[n - 1] + 1;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(__null);
    
    int64 n, x; cin >> n >> x;

    a[0] = 1; p[0] = 1;
    for (int i = 1; i < n; ++i){
        a[i] = 2 * a[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }

    print(rec(n, x));

    return 0;
}