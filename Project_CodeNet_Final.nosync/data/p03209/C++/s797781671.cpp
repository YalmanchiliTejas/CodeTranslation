/**
*    created: 20.06.2020 03:08:44
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

int f(int n, int x) {
    if (n == 0) return 1;
    else if (x == 1) return 0;    
    int l1 = (1LL << (n+1)) - 3;
    int l2 = (1LL << n) - 1;
    if (x <= l1 + 1) return f(n-1,x-1);
    else if (x == l1 + 2) return (l2 + 1);
    else if (x >= l1 + 3 && x <= l1 * 2 + 2) return (l2 + 1 + f(n-1,x-l1-2));
    else return 2 * l2 + 1;
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    cout << f(n,x) << endl;
    return 0;
}