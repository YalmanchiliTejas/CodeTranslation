#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e18 + 200;

int a[N], L[N], bestL[N], bestR[N], R[N], n;

main(){
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        L[i] = a[i];
        if (i >= 2) L[i] += L[i - 2];
    }
    for (int i = 1; i < n; i += 2)
        bestL[i] = max(L[i - 1], a[i] + (i - 2 >= 0? bestL[i - 2]: 0));
    if (n % 2 == 0) {
       	cout << bestL[n - 1];
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        R[i] = a[i];
        if (i + 2 < n) R[i] += R[i + 2];
    }
    for (int i = n - 2; i >= 0; i -= 2)
        bestR[i] = max(R[i + 1], a[i] + (i + 2 < n? bestR[i + 2]: 0));
    int res = L[n - 2];
    for (int i = 0; i + 1 < n; i++){
        if (i % 2 == 0) {
            int cand = 0;
            if (i - 1 >= 0) cand += bestL[i - 1];
            if (i + 2 < n) cand += R[i + 2];
            res = max(res, cand);
        } else {
            int cand = 0;
            if (i - 1 >= 0) cand += L[i - 1];
            if (i + 2 < n) cand += bestR[i + 2];
            res = max(res, cand);
        }
    }
    cout << res << endl;
    return 0;
}










