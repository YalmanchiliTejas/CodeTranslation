#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n;
int s[Maxn];
map <ii, ll> L;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = i; j < n; j += i) {
            cur += s[j];
            L[ii(i, j)] = cur;
        }
    }
    for (int i = 1; i <= n; i++) {
        ll cur = 0;
        for (int j = n - 1 - i; j > 0; j -= i) {
            cur += s[j];
            int b = j - i;
            if (0 < b && b < j && (j % i || (n - 1 - j) / i < j / i))
                res = max(res, cur + L[ii(i, n - 1 - j)]);
        }
    }
    cout << res << endl;
    return 0;
}
