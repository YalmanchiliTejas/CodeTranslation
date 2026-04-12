#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);

        vector<int> res;
        res.push_back(a[0]);
        for (int i = 1; i < n; i += 2) res.push_back(a[i]);
        reverse(res.begin(), res.end());
        for (int i = 2; i < n; i += 2) res.push_back(a[i]);
        if (n % 2 == 1) reverse(res.begin(), res.end());
        for (int i = 0; i < n; i++) printf("%d%c", res[i], " \n"[i + 1 == n]);
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}