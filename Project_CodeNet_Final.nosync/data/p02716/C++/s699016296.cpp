#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll L[Maxn], R[Maxn];
ll bestL[Maxn], bestR[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        L[i] = a[i];
        if (i >= 2) L[i] += L[i - 2];
    }
    for (int i = 1; i < n; i += 2)
        bestL[i] = max(L[i - 1], a[i] + (i - 2 >= 0? bestL[i - 2]: 0));
    if (n % 2 == 0) {
        printf("%lld\n", bestL[n - 1]);
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        R[i] = a[i];
        if (i + 2 < n) R[i] += R[i + 2];
    }
    for (int i = n - 2; i >= 0; i -= 2)
        bestR[i] = max(R[i + 1], a[i] + (i + 2 < n? bestR[i + 2]: 0));
    ll res = L[n - 2];
    for (int i = 0; i + 1 < n; i++)
        if (i % 2 == 0) {
            ll cand = 0;
            if (i - 1 >= 0) cand += bestL[i - 1];
            if (i + 2 < n) cand += R[i + 2];
            res = max(res, cand);
        } else {
            ll cand = 0;
            if (i - 1 >= 0) cand += L[i - 1];
            if (i + 2 < n) cand += bestR[i + 2];
            res = max(res, cand);
        }
    cout << res << endl;
    return 0;
}
