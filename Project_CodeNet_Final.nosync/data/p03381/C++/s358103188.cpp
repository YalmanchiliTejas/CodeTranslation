#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N], p[N], ans[N];
bool cmp(int i, int j) {return a[i] < a[j];}
int main()
{
    int n; cin >> n;
    int k = n/2;
    for (int i = 0; i < n; i++) cin >> a[i], p[i] = i;
    sort(p, p + n, cmp);
    for (int i = 0; i < k; i++) ans[p[i]] = a[p[k]];
    for (int i = k; i < n; i++) ans[p[i]] = a[p[k - 1]];
    for (int i = 0; i < n; i++) cout << ans[i] << "\n";

    return 0;
}
